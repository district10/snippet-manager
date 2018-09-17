python3 -m pip install PyOpenGL PyOpenGL_accelerate

# https://github.com/uoip/pangolin
git clone https://github.com/uoip/pangolin.git
cd pangolin
mkdir build
cd build
cmake ..
make -j8
cd ..
python3 setup.py install
