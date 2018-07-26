FROM ubuntu:16.04

RUN apt-get update && apt-get install -y vim wget curl git unzip zsh
RUN wget https://github.com/robbyrussell/oh-my-zsh/raw/master/tools/install.sh -O - | zsh || true
RUN git clone --depth 1 https://github.com/junegunn/fzf.git ~/.fzf && printf "y\ny\ny\n" | ~/.fzf/install
RUN apt-get install -y python-dev 
RUN wget https://bootstrap.pypa.io/get-pip.py -O - | python 
RUN pip install percol
RUN cd /tmp && curl -L -o pt_linux_amd64.tar.gz "https://github.com/monochromegane/the_platinum_searcher/releases/download/v2.1.6/pt_linux_amd64.tar.gz" && \
    tar zxvf pt_linux_amd64.tar.gz && cp pt_linux_amd64/pt /bin
RUN echo "source /workdir/sm.sh" >> /root/.zshrc

RUN apt-get -y install locales
RUN sed -i -e 's/# en_US.UTF-8 UTF-8/en_US.UTF-8 UTF-8/' /etc/locale.gen && locale-gen
ENV LANG en_US.UTF-8  
ENV LANGUAGE en_US:en  
ENV LC_ALL en_US.UTF-8   

WORKDIR /workdir
ADD . /workdir
# or use volume:
#   Dockerfile:
#   - ADD . /workdir
#   Makefile:
#   - docker run -it crowdsource_frontend zsh
#   + docker run -v `pwd`:/workdir -it crowdsource_frontend zsh
#
#   Docker volume: https://docs.docker.com/storage/volumes/

CMD ["zsh"]
