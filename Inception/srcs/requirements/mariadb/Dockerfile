FROM debian:buster

RUN apt-get update && apt-get upgrade -y \
	&& apt-get -y install wget
RUN apt-get -y install mariadb-server

COPY ./tools/start.sh /usr/local/bin
CMD bash /usr/local/bin/start.sh;
