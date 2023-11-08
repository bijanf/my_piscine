#import xarray as xr
import xarray as xr import dask.array as da

import os 
file1="pr_ukesm1-0-ll_r1i1p1f2_ssp585_90arcsec_2065-2100__46_89_33_45.26_updated.nc"
file2="pr_ukesm1-0-ll_r1i1p1f2_ssp585_90arcsec_2065-2100__46_89_45_60_updated.nc"
out="pr_ukesm1-0-ll_r1i1p1f2_ssp585_90arcsec_2065-2100_CA_updated.nc"
#os.system("cdo collgrid "+file1+" "+file2+" "+out)
#os.system("cdo smooth9,sigmax=0.5,lonlat  pr_ukesm1-0-ll_r1i1p1f2_ssp585_90arcsec_2065-2100_CA_updated.nc smoothed.nc")
#ds1 = xr.open_dataset(file1)
#ds2 = xr.open_dataset(file2)
#print(ds1)
#print(ds2)

#merged_ds = xr.concat([ds1, ds2], dim='lat')

#merged_ds.to_netcdf("pr_ukesm1-0-ll_r1i1p1f2_ssp585_90arcsec_2065-2100_CA_updated.nc")
#"cdo collgrid pr_ukesm1-0-ll_r1i1p1f2_ssp585_90arcsec_2065-2100__46_89_33_45.26_updated.nc pr_ukesm1-0-ll_r1i1p1f2_ssp585_90arcsec_2065-2100__46_89_45_60_updated.nc test.nc"

import netCDF4 as nc


import netCDF4 as nc
import scipy.ndimage as nd

# Open the netcdf file
ncfile = nc.Dataset ('pr_ukesm1-0-ll_r1i1p1f2_ssp585_90arcsec_2065-2100_CA_updated.nc', 'r')
#print(ncfile)
# Read the data variable (assuming it is called 'data')
var = ncfile.variables['pr'][:]
#print(var)
#scale_factor = var.scale_factor
#add_offset = var.add_offset
#data = (var [:] - add_offset) / scale_factor
data = var.astype(np.int16)

print(data.shape)
# Apply the Gaussian filter along the latitude axis
smoothed_data = data
#for i in range(1,3):
smoothed_data  = nd.gaussian_filter(data, sigma=.5)

smoothed_data[:,340:610,:]  = nd.gaussian_filter(smoothed_data[:,340:610,:], sigma=.5)
smoothed_data[:,460:500,:]  = nd.gaussian_filter(smoothed_data[:,460:500,:], sigma=8)
smoothed_data[:,450:470,:]  = nd.gaussian_filter(smoothed_data[:,450:470,:], sigma=5)
smoothed_data[:,440:460,:]  = nd.gaussian_filter(smoothed_data[:,440:460,:], sigma=5)

smoothed_data[:,490:520,:]  = nd.gaussian_filter(smoothed_data[:,490:520,:], sigma=5)
smoothed_data[:,480:530,:]  = nd.gaussian_filter(smoothed_data[:,480:530,:], sigma=2)
smoothed_data[:,350:600,:]  = nd.gaussian_filter(smoothed_data[:,350:600,:], sigma=.5)
smoothed_data[:,355:595,:]  = nd.gaussian_filter(smoothed_data[:,355:595,:], sigma=1)
smoothed_data[:,360:590,:]  = nd.gaussian_filter(smoothed_data[:,360:590,:], sigma=1)
smoothed_data[:,400:550,:]  = nd.gaussian_filter(smoothed_data[:,400:550,:], sigma=1)
smoothed_data[:,350:600,:]  = nd.gaussian_filter(smoothed_data[:,350:600,:], sigma=.5)

#smoothed_data[:,400:550,:]  = nd.gaussian_filter(smoothed_data[:,400:550,:], sigma=2)
#smoothed_data[:,477:483,:]  = nd.gaussian_filter(smoothed_data[:,477:483,:], sigma=1)
#smoothed_data[:,475:485,:] = nd.gaussian_filter(smoothed_data[:,475:485,:], sigma=1)
#smoothed_data[:,473:487,:] = nd.gaussian_filter(smoothed_data[:,473:487,:], sigma=1)
#smoothed_data[:,470:490,:]= nd.gaussian_filter(smoothed_data[:,470:490,:], sigma=1)
#smoothed_data[:,470:490,:]  = nd.gaussian_filter(smoothed_data[:,470:490,:], sigma=1)
#smoothed_data[:,467:493,:]  = nd.gaussian_filter(smoothed_data[:,467:493,:], sigma=1)
# Read the _FillValue attribute from the original data variable
fill_value = ncfile.variables ['pr'].getncattr ('_FillValue')
# Close the netcdf file
ncfile.close ()


# Open the original netcdf file
ncfile = nc.Dataset ('test.nc', 'r')

# Read the dimensions and attributes of the original file
lon = ncfile.variables ['lon'] [:]
lat = ncfile.variables ['lat'] [:]
attrs = ncfile.variables ['pr'].ncattrs ()

# Close the original netcdf file
#ncfile.close ()

# Create a new netcdf file
newfile = nc.Dataset ('pr_ukesm1-0-ll_r1i1p1f2_ssp585_90arcsec_2065-2100_CA_updated_smoothed.nc', 'w')

# Define the dimensions of the new file
newfile.createDimension ('lat', len (lat))
newfile.createDimension ('lon', len (lon))

# Create a variable for the smoothed data
smoothed_var = newfile.createVariable ('pr', 'f4', ('lat', 'lon'),fill_value=fill_value)

# Write the smoothed data to the new file
smoothed_var[:] = smoothed_data.squeeze()
# Copy the attributes of the original data variable to the new one
for attr in attrs:
    if attr != '_FillValue': # Skip the _FillValue attribute since it is already set
        smoothed_var.setncattr(attr, ncfile.variables ['pr'].getncattr(attr))

# Close the new netcdf file
newfile.close ()
ncfile.close ()
