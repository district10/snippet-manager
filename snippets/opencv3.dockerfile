FROM ubuntu:16.04

# dockerfile opencv 3
ENV OpenCV_DIR=/usr/local/share/OpenCV

RUN echo "\n\
deb http://cn.archive.ubuntu.com/ubuntu/ xenial main restricted\n\
deb http://cn.archive.ubuntu.com/ubuntu/ xenial-updates main restricted\n\
deb http://cn.archive.ubuntu.com/ubuntu/ xenial universe\n\
deb http://cn.archive.ubuntu.com/ubuntu/ xenial-updates universe\n\
deb http://cn.archive.ubuntu.com/ubuntu/ xenial multiverse\n\
deb http://cn.archive.ubuntu.com/ubuntu/ xenial-updates multiverse\n\
deb http://cn.archive.ubuntu.com/ubuntu/ xenial-backports main restricted universe multiverse\n\
deb http://security.ubuntu.com/ubuntu xenial-security main restricted\n\
deb http://security.ubuntu.com/ubuntu xenial-security universe\n\
deb http://security.ubuntu.com/ubuntu xenial-security multiverse" > /etc/apt/sources.list

RUN apt-get update && apt-get install -y build-essential cmake curl git pkg-config unzip vim wget
RUN apt-get install -y libboost-all-dev

RUN apt-get install -y \
    freeglut3-dev libatlas-base-dev \
    libblas-dev libeigen3-dev libgl1-mesa-dev libglu1-mesa-dev
RUN apt-get install -y \
    libjpeg-dev liblapack-dev libpng-dev \
    libtiff-dev libv4l-dev libxi-dev libxmu-dev

# RUN git clone https://github.com/opencv/opencv.git /opencv && cd /opencv && git checkout 3.4
RUN cd /tmp && wget http://7vzps8.com1.z0.glb.clouddn.com/opencv3_archive.zip && \
    unzip opencv3_archive.zip && \
    mv /tmp/opencv3_archive/opencv-3.4 /opencv && \
    cd /opencv && mkdir build && cd build && \
    cmake -D CMAKE_BUILD_TYPE=RELEASE -D WITH_IPP=OFF -D WITH_V4L=OFF .. && make -j8 && make install

RUN cd /tmp && curl -O http://download.osgeo.org/proj/proj-4.9.3.tar.gz && \
    tar xvf proj*.gz && cd proj* && \
    mkdir build && cd build && cmake .. && make && make install

RUN wget https://bootstrap.pypa.io/get-pip.py && python get-pip.py
RUN pip install requests pyyaml awscli # pip install yaml # python yaml

RUN rm -rf /tmp/* /opencv
# RUN rm -rf /var/lib/apt/lists/* # du -sh /var/lib/apt/lists
