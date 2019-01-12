sudo groupadd docker
sudo usermod -aG docker $USER
sudo chown $USER:docker /var/run/docker.sock
# chmod 666 /var/run/docker.sock 
# Is the docker daemon running on this host?
sudo service docker restart
newgrp - docker

docker image ls
docker image ls --filter "dangling=false"
docker images --filter "dangling=false"
