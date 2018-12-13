ENV PATH /opt/conda/bin:$PATH
RUN wget --quiet https://mirrors.tuna.tsinghua.edu.cn/anaconda/miniconda/Miniconda3-4.4.10-Linux-x86_64.sh -O ~/anaconda.sh && \
    /bin/bash ~/anaconda.sh -b -p /opt/conda && \
    rm ~/anaconda.sh && \
    ln -s /opt/conda/etc/profile.d/conda.sh /etc/profile.d/conda.sh && \
    echo ". /opt/conda/etc/profile.d/conda.sh" >> ~/.zshrc
RUN pip install --upgrade pip && pip install scipy matplotlib numpy pyproj transforms3d opencv-python opencv-contrib-python dataclasses
RUN apt install -y libsm6 libxext6 libxrender-dev # fix 'import cv2'
