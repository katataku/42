FROM debian:buster

RUN apt-get update && apt-get upgrade -y

#----------------------------------- 2. Intall Dependencies --------------------------------------
# Sysvinit-utils for "service" command used to easily start and restart our nginx/php/mysql
RUN apt-get install sysvinit-utils

# Wget is used to easily download phpMyAdmin / Wordpress
RUN apt-get -y install wget

# Nginx is an open source web server tool we are going to use to connect our Docker container image to our webpage
RUN apt-get -y install nginx

# MariaDB is a tool used to manage databases. It's a community "fork" of MySQL (= improved version of MySQL)
RUN apt-get -y install mariadb-server

COPY ./srcs/start.sh ./

# Every other command in Dockerfile is executed while "building" our container
# CMD tells Docker the default command to execute when we are "running" our container
CMD bash start.sh;

