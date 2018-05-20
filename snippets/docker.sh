docker build -t smart:v1 .                  # tag an image
docker info
docker login <ip:port>
docker logs
docker logs --help
docker pull tensorflow/tensorflow

docker cp hash:/path/to/file host/path
docker kill <hash>

docker save -o image.tar java-8/java-8:release-latest
docker load -i image.tar
