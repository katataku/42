FROM debian:buster

RUN apt-get update && apt-get upgrade -y \
	&& apt-get -y install wget \
	&& apt-get -y install php-cgi php-common php-fpm php-pear php-mbstring \
			php-zip php-net-socket php-gd php-xml-util php-gettext php-mysql php-bcmath mariadb-client

WORKDIR /var/www/localhost/

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	&& chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp \
	&& mkdir -p /var/www/localhost/wordpress

RUN mkdir -p /var/run/php/ \
	&& mkdir -p /var/log/php/ \
	&& touch /var/log/php/access.log \
	&& touch /var/log/php/error.log
	
COPY ./srcs/www.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY ./tools/start.sh /usr/local/bin
CMD bash /usr/local/bin/start.sh;