# docker mount volume
Dockerfile:             WORKDIR /workdir
Makefile:               docker run -v `pwd`:/workdir -it hash zsh

Dockerfile:             WORKDIR /workdir
                        add . /workdir
Makefile:               docker run -it hash zsh
