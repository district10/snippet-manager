# ubuntu dockerfile
FROM ubuntu:16.04

RUN apt-get update && apt-get install -y build-essential cmake curl git pkg-config unzip vim wget
RUN apt-get install -y libboost-all-dev

# better use .dockerigonre
WORKDIR /workdir
ADD . /workdir

CMD ["make", "run"]
