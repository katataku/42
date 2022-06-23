FROM debian:buster

RUN apt-get update && apt-get upgrade -y \
	&& apt-get -y install wget
RUN apt-get -y install nginx


RUN mkdir /var/www/localhost
COPY srcs/localhost /etc/nginx/sites-available
RUN ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled
RUN openssl req -x509 \
				-nodes \
				-days 30 \
				-subj "/C=JP/ST=Kanagawa/L=Kawasaki/O=42 Tokyo/OU=student/CN=takkatao.42.fr" \
				-newkey rsa:2048 \
				-keyout /etc/ssl/nginx-selfsigned.key \
				-out /etc/ssl/nginx-selfsigned.crt;

COPY ./tools/start.sh /usr/local/bin
CMD bash /usr/local/bin/start.sh;
