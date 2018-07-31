FROM ubuntu:16.04

RUN apt-get update && apt-get install -y vim wget curl git unzip zsh
RUN wget https://github.com/robbyrussell/oh-my-zsh/raw/master/tools/install.sh -O - | zsh || true
RUN git clone --depth 1 https://github.com/junegunn/fzf.git ~/.fzf && printf "y\ny\ny\n" | ~/.fzf/install
COPY install.sh /tmp/install.sh
RUN bash /tmp/install.sh
RUN echo "source /workdir/sm.sh" >> /root/.zshrc

RUN apt-get -y install locales
RUN sed -i -e 's/# en_US.UTF-8 UTF-8/en_US.UTF-8 UTF-8/' /etc/locale.gen && locale-gen
ENV LANG en_US.UTF-8  
ENV LANGUAGE en_US:en  
ENV LC_ALL en_US.UTF-8   

WORKDIR /workdir
ADD . /workdir

CMD ["true"]
