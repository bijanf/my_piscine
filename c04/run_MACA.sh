#!/bin/bash 
##SBATCH --qos=short                                                                                                                                             
#SBATCH --qos=priority
###SBATCH --partition=standard
#SBATCH --partition=priority  
###SBATCH --partition=largemem                                                                                              
#SBATCH --account=gvca                                                                                                                                          
#SBATCH --ntasks=1                                                                                                                                              
#SBATCH --cpus-per-task=16                                                                                                                                      
#SBATCH --job-name=downscale                                                                                                                                   
#SBATCH --output=slogs/out.%j                                                                                                                                   
#SBATCH --error=slogs/out.%j           
##conda activate base
module load nco
##module load cdo
module load cdo/2.0.5/gnu/10.2


#python MACA.py 
#python post_process.py
python merge_netcdfs_dask.py
