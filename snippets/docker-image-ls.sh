sudo groupadd docker
sudo usermod -aG docker $USER
sudo chown $USER:docker /var/run/docker.sock
sudo service docker restart
newgrp - docker

docker image ls
docker image ls --filter "dangling=false"
docker images --filter "dangling=false"
