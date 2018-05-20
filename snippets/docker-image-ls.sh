sudo usermod -aG docker $USER
sudo chown $USER:docker /var/run/docker.sock
sudo service docker restart
docker image ls
