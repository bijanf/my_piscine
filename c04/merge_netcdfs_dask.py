#import xarray as xr
import xarray as xr 
import dask.array as da

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
chunks = {"lat": 100, "lon": 100}
ds1 = xr.open_dataset(file1, chunks=chunks)
ds2 = xr.open_dataset(file2, chunks=chunks)
print('chunking finished----------------------------------')
merged_ds = xr.concat([ds1, ds2], dim="lat")
merged_ds.pr.encoding["_FillValue"] = 1e20
merged_ds.pr.encoding["missing_value"] = 1e20
merged_ds.to_netcdf(out)
###############
print("start the smoothing")

data = xr.open_dataset(out, chunks=chunks)
smoothed_data = data.pr.data.map_blocks(da.ndimage.gaussian_filter, sigma=0.5)
smoothed_data[:, 340:610, :] = smoothed_data[:, 340:610, :].map_blocks(da.ndimage.gaussian_filter, sigma=0.5)
smoothed_data[:, 460:500, :] = smoothed_data[:, 460:500, :].map_blocks(da.ndimage.gaussian_filter, sigma=8) 
smoothed_data[:, 450:470, :] = smoothed_data[:, 450:470, :].map_blocks(da.ndimage.gaussian_filter, sigma=5)
smoothed_data[:, 440:460, :] = smoothed_data[:, 440:460, :].map_blocks(da.ndimage.gaussian_filter, sigma=5)
smoothed_var = xr.DataArray(smoothed_data, coords=data.pr.coords, attrs=data.pr.attrs)
smoothed_ds = xr.Dataset({"pr": smoothed_var})
smoothed_ds.to_netcdf("pr_ukesm1-0-ll_r1i1p1f2_ssp585_90arcsec_2065-2100_CA_updated_smoothed.nc")
print('----------------------FINISHED----------------------')