# for pip users
python -m pip install --user numpy matplotlib opencv-python;

# for anaconda users
conda create --name py36_open3d python=3.6
source activate py36_open3d
conda install -y numpy matplotlib
conda install -y -c conda-forge opencv
