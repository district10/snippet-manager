docker build .
docker build - < Dockerfile

    FROM ubuntu:16.04

    ENV USE_NATIVE_G2O true
    ENV DISABLE_TEST true

    RUN echo "deb http://archive.ubuntu.com/ubuntu precise main universe" > /etc/apt/sources.list
    RUN apt-get update && apt-get install -y git cmake build-essential \
            libblas-dev liblapack-dev libeigen3-dev \
            libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev \
            libxmu-dev libxi-dev libopencv-dev && \
            cd /tmp && curl -O http://download.osgeo.org/proj/proj-4.9.3.tar.gz && \
            tar xvf proj*.gz && cd proj* && \
            mkdir build && cd build && cmake .. && make && make install

    CMD ["bash"]

docker build github.com/creack/docker-firefox
