#####################################################
#||Downscaling the CMIP6 bias-adjusted simulation  ||
#||                   using the                    ||
#||Multivariate Adaptive Constructed Analogs (MACA)||
#####################################################

# This is the code to do the MACA downscaling 
# refer to this document 
# https://kerwa.ucr.ac.cr/bitstream/handle/10669/29838/CEC-500-2007-123.PDF?sequence=1
'''
Author: Bijan Fallah 
Email: bijan.fallah@gmail.com

'''
# import the libraries : 
# ----------------------

from skdownscale.pointwise_models import BcsdTemperature, BcsdPrecipitation
from skdownscale.pointwise_models import PointWiseDownscaler
from skdownscale.pointwise_models import AnalogRegression, PureAnalog
import xarray as xr
from tqdm import tqdm 
import xarray_regrid
import numpy as np
import pandas as pd 
import os
# import the SimpleImputer class
from sklearn.impute import SimpleImputer

# create an instance of the imputer with strategy='mean'
imputer = SimpleImputer(strategy='mean')

#import rioxarray
#====================================== N A M E    L I S T =======================================
#-----------------------------------
lon0=46
lon1=89


lat0=33
#lat0=45
lat1=45.26
#lat1=60
#------------------------------------
year_fut_start=2065
year_fut_end=2100
model_name = "ukesm1-0-ll_r1i1p1f2"
ssps="ssp585"
# load datasets : 
dir="/p/tmp/fallah/test_downscale/scripts/data/merged/"
var="pr_"
# simulation hist:
sim_h = dir+model_name+"_w5e5_historical_"+var+"global_daily_lat30.00_60.00_lon40.00_90.00_cut_mergetime.nc"
sim_hist = xr.open_dataset(sim_h)
sim_hist = sim_hist.sel(time=slice("1979","2014"))
sim_hist = sim_hist.sel(lon=slice(lon0, lon1), lat=slice(lat1, lat0))
sim_hist = sim_hist.reindex(lat=sim_hist.lat[::-1])
#sim_hist = sim_hist.transpose("time", "lon", "lat")
print("sim_hist",sim_hist)
print("+++++++++++++++++++++++++++++++++++++++++++++++")
# obs fine 
#obs_fine = xr.open_dataset(dir+"obs_fine.nc")
obs_f = dir+"chelsa-w5e5v1.0_obsclim_"+var+"90arcsec_global_daily__lat30.00_60.00_lon40.00_90.00_cut_mergetime.nc"
obs_fine = xr.open_dataset(obs_f)
obs_fine = obs_fine.sel(lon=slice(lon0,lon1), lat=slice(lat0, lat1))
print("obs_fine",obs_fine)
print("+++++++++++++++++++++++++++++++++++++++++++++++")
#-----------------------------------------------------------------------
# create the obs coarse      
#                                ukesm1-0-ll_r1i1p1f2_w5e5_historical_pr_global_daily_lat30.00_60.00_lon40.00_90.00_cut_mergetime.nc                                    
cmd = "cdo -O -remapcon,"+sim_h+" "+obs_f+" "+dir+"obs_coarse.nc"
##########os.system(cmd) #############################################################<<<<<<<<<<<<<<<<<<
# finished the obse coarse 
#-----------------------------------------------------------------------
# 
obs_coarse = xr.open_dataset(dir+"obs_coarse.nc")
#print("1", obs_coarse)
obs_coarse = obs_coarse.sel(lon=slice(lon0, lon1), lat=slice(lat1,lat0))
obs_coarse = obs_coarse.reindex(lat=obs_coarse.lat[::-1])
#obs_coarse = obs_coarse.transpose("time", "lon", "lat")
print("obs_coarse", obs_coarse)
print("++++++++++++++++++++++++++") 

# simulation future:
sim_fut = xr.open_dataset(dir+model_name+"_w5e5_"+ssps+"_"+var+"global_daily_lat30.00_60.00_lon40.00_90.00_cut_mergetime.nc")
sim_fut = sim_fut.sel(time=slice(str(year_fut_start),str(year_fut_end)))
sim_fut = sim_fut.sel(lon=slice(lon0, lon1), lat=slice(lat1, lat0))
sim_fut = sim_fut.reindex(lat=sim_fut.lat[::-1])
#sim_fut = sim_fut.transpose("time", "lon", "lat")

print("sim_fut", sim_fut)
print("+++++++++++++++++++++++++++++++++++++++++++++++")
#sim_fut = xr.open_dataset(dir+"GCM_fut_"+str(year_fut_start)+"-"+str(year_fut_end)+".nc")
#-----------------------------------------------------------------------
# ==================================================================================================
# calculate the 21-day rolling average over historical periods
mean_obs_coarse = obs_coarse.pr.rolling(time=21, center=True).mean()
# calculate the historical mean slice

annual_mean_obs_coarse = mean_obs_coarse.groupby('time.dayofyear').mean()
# calculate the 21-day rolling average over control period
mean_hist = sim_hist.sel(time=slice("1979","2014")).rolling(time=21, center=True).mean()
# calculate the historical mean slice
#print(mean_hist)
annual_mean_hist = mean_hist.groupby('time.dayofyear').mean()
# calculate the 21-day rolling average over future period
mean_fut = sim_fut.pr.sel(time=slice(str(year_fut_start),str(year_fut_end))).rolling(time=21, center=True).mean()
# calculate the historical mean slice
annual_mean_fut = mean_fut.groupby('time.dayofyear').mean()
# epoch adjustment
# for future period
sim_fut_epoch_adjust = sim_fut.sel(time=slice(str(year_fut_start),str(year_fut_end))).groupby('time.dayofyear') / (annual_mean_fut/annual_mean_hist)
sim_fut_epoch_adjust.load()
############################

############################

def flatten_data(data_array):
    len_d,len_lat,len_lon = np.shape(data_array.values)
    df_train = pd.DataFrame(np.reshape(data_array.values,[len_d,len_lat*len_lon]),
                             index=data_array.time.values)
     
    # impute instead of droping: 
    #df_train = df_train.dropna(axis=1)
    # fit and transform the data frame with missing values
    #df_train = df_train.fillna(method='ffill', axis=0)
    df_train.fillna(value=0, inplace=True)
    #df_train_imputed = imputer.fit_transform(df_train)
    # convert the result to a data frame
    #df_train = pd.DataFrame(df_train_imputed, columns=df_train.columns,index=df_train.index)
    
    return df_train

# preprocess: flatten the domain (2D) into a 1D array
df_train = flatten_data(obs_coarse.pr)
#df_f = flatten_data(sim_fut_epoch_adjust.pr.sel(time=slice(str(year_fut_start),str(year_fut_end))))
df_f = flatten_data(sim_fut_epoch_adjust.pr)

# calculate RMSE using matrix calculation to avoid replicate
# RMSE = (1/n) * sqrt(sum_i((d_i-p_i)^2))
# calculate di*pi

df_cross = df_train.dot(df_f.T)
# calculate di^2
df_train_power_2 = pd.DataFrame(df_train.pow(2).sum(axis=1))
df_train_power_2 = pd.concat([df_train_power_2]*len(df_f),axis=1)
df_train_power_2.columns = df_f.index.values
# calculate pi^2
df_f_power_2 = pd.DataFrame(df_f.pow(2).sum(axis=1))
df_f_power_2 = pd.concat([df_f_power_2]*len(df_train),axis=1).T
df_f_power_2.index = df_train.index.values
# calcuate RMSE
sum_ = df_train_power_2+ df_f_power_2 - df_cross.multiply(2)
rmse = np.sqrt(sum_)/np.shape(df_f)[1]
# for each dayofyear, find start/end day of year
start = np.arange(1,367)-45
start[start<=0] += 365

end = np.arange(1,367)+45
end[end>=366] -= 365
df_index = pd.DataFrame(np.transpose([start,end]),index=np.arange(1,367), columns=['start','end'])
# create an empty array 
# remove 20 grids on the boundaries 
#empty_array = np.empty((sim_fut.pr.data.shape[0], obs_fine.pr.shape[1]-20, obs_fine.pr.shape[2]-20), dtype=np.float32)
empty_array = np.memmap('data.dat', mode='w+', shape=(sim_fut.pr.data.shape[0], obs_fine.pr.shape[1]-10, obs_fine.pr.shape[2]-20), 
                        dtype=np.float32, offset=0)

for ind in tqdm(range(1)): # loop over all days in sim_fut
    # Look up the start/end day of year based on the table
    time_tar = sim_fut_epoch_adjust.time.values[ind]
    doy_tar = pd.to_datetime(time_tar).dayofyear
    doy_start = df_index.start.loc[doy_tar]
    doy_end = df_index.end.loc[doy_tar]

    # Sort the rows based on RMSE
    df_sel = pd.DataFrame(rmse[time_tar]).sort_values(time_tar)
    df_sel['dayofyear']=df_sel.index.dayofyear
    df_up = df_sel[(df_sel['dayofyear']<doy_end)|(df_sel['dayofyear']>doy_start)]

    # Find 30 best fit with lowest RMSE
    time_sel = df_up.index[0:30]
    # Find the 30 best fit
    top_parttern_coarse =  obs_coarse.pr.sel(time=time_sel)
    top_pattern_fine = obs_fine.pr.sel(time=time_sel)
    # calculate the coefficient
    df_coarse = flatten_data(top_parttern_coarse)
    df_coarse.index=np.arange(30)
    df_coarse.columns=np.arange(len(df_coarse.columns))

    # calculate the inverse of a matrix
    # np.linalg.pinv is preferred than inv here
   
    df_inverse = pd.DataFrame(np.linalg.pinv(df_coarse.dot(df_coarse.T).values))
    # calculate the observed dataframe
    x = np.ravel(sim_fut_epoch_adjust.pr.sel(time=time_tar).values)
    x = x[~np.isnan(x)]
    df_obs = pd.DataFrame(x)

    # calculate the coefficient
    
    df_coefficient = (df_inverse.dot(df_coarse)).dot(df_obs)
    # find the fine resolution map

    # step1: transform coefficient into xr.Dataarray 
    ds_coeff = xr.DataArray(np.ravel(df_coefficient.values),dims='time',
                            coords=[top_pattern_fine.time.values])
    
    #step2: calculate the fine resolution
    ds_fine_resoluation = (top_pattern_fine*ds_coeff).mean(dim='time')
    #ds_fine_resoluation = ds_fine_resoluation.where(ds_fine_resoluation >= 0, 0.0)
    ds_fine_resoluation = ds_fine_resoluation.where(ds_fine_resoluation >= 0, 0.0)
    # adding random limits to precipitation not letting it to go beyond the 150% of the coarse grid!
    ds_coarse_resoluation = sim_fut.pr.sel(time=time_tar)

    lat_min = obs_coarse.lat.min()
    lat_max = obs_coarse.lat.max()
    lon_min = obs_coarse.lon.min()
    lon_max = obs_coarse.lon.max()
    
    ds_coarse_regrid = ds_coarse_resoluation.to_dataset().regrid.regrid(ds_fine_resoluation, method="linear")
    ds_coarse_regrid = ds_coarse_regrid.sel(lat=slice(lat_min, lat_max), lon=slice(lon_min, lon_max))
    ds_fine_resoluation = ds_fine_resoluation.sel(lat=slice(lat_min, lat_max), lon=slice(lon_min, lon_max))
    # write it to the empty data           
    empty_array[ind,:,:] = ds_fine_resoluation
    
    #del ds_fine_resoluation, ds_coeff, df_coefficient, df_obs, x, df_inverse, df_coarse, top_parttern_coarse
    #del top_pattern_fine, time_sel, df_up, df_sel, time_tar, doy_start, doy_end, doy_tar 

#######################################
# Write the result into a netcdf file 
#######################################
# create a DataArray object from the array
empty_da = xr.DataArray(empty_array)
#empty_da.to_netcdf('test_fine.nc')

#empty_array.flush()
# optionally, you can also specify the dimensions and coordinates for the DataArray
print("------------------------", empty_da)
print("****************************")
print(ds_coarse_regrid)
print("****************************")
print("obs_fine",obs_fine)
print("****************************")
print('lat', ds_coarse_regrid.lat.data, 'lon', ds_coarse_regrid.lon.data)

dims = ('time', 'lat','lon')
coords = {'time': sim_fut.time.data ,'lat': ds_coarse_regrid.lat.data,
           'lon': ds_coarse_regrid.lon.data}

sim_fut_fine = xr.DataArray(empty_array, name='pr', dims=dims, coords=coords)
# write the DataArray to a netcdf file 
##########sim_fut_fine.to_netcdf('sim_fut_fine.nc')


# load the existing netcdf file as a Dataset object
ds = xr.open_dataset('pr_ukesm1-0-ll_r1i1p1f2_ssp585_90arcsec_2065-2100_46_89_33_45.26.nc')

# set or update the attributes for the time dimension
ds.time.attrs['standard_name'] = 'time'
ds.time.attrs['long_name'] = 'time'
ds.time.attrs['units'] = 'days since 2015-1-1 00:00:00'
ds.time.attrs['calendar'] = 'proleptic_gregorian'
ds.time.attrs['axis'] = 'T'
# delete or pop the units attribute from the time dimension

ds.time.attrs.pop('units')
ds.time.attrs.pop('calendar')
# set or update the attributes for the lon coordinate
ds.lon.attrs['standard_name'] = 'longitude'
ds.lon.attrs['long_name'] = 'Longitude'
ds.lon.attrs['units'] = 'degrees_east'
ds.lon.attrs['axis'] = 'X'

# set or update the attributes for the lat coordinate
ds.lat.attrs['standard_name'] = 'latitude'
ds.lat.attrs['long_name'] = 'Latitude'
ds.lat.attrs['units'] = 'degrees_north'
ds.lat.attrs['axis'] = 'Y'

# set or update the attributes for the pr variable
ds.pr.attrs['standard_name'] = 'precipitation_flux'
ds.pr.attrs['long_name'] = 'Precipitation'
ds.pr.attrs['units'] = 'kg m-2 s-1'
ds.pr.attrs['missing_value'] = 1.e+20

# write the Dataset to a new netcdf file with the updated attributes
years_date= '_'+str(lon0)+'_'+str(lon1)+'_'+str(lat0)+'_'+str(lat1)

ds.to_netcdf(var+model_name+'_'+ssps+'_90arcsec_'+str(year_fut_start)+"-"+str(year_fut_end)+'_'+years_date+'_updated.nc')


del ds 
del empty_array
del empty_da

