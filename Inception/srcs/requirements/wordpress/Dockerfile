FROM debian:buster

RUN apt-get update && apt-get upgrade -y

#----------------------------------- 2. Intall Dependencies --------------------------------------
# Sysvinit-utils for "service" command used to easily start and restart our nginx/php/mysql
RUN apt-get install sysvinit-utils

# Wget is used to easily download phpMyAdmin / Wordpress
RUN apt-get -y install wget

# Nginx is an open source web server tool we are going to use to connect our Docker container image to our webpage
RUN apt-get -y install nginx


# Php packages are needed to read our configuration files and properly connect all of our components together
# In case a php package is missing, we will get an error when launching php related services later
RUN apt-get -y install php-cgi php-common php-fpm php-pear php-mbstring \
						php-zip php-net-socket php-gd php-xml-util php-gettext php-mysql php-bcmath mariadb-client
#-------------------------------------------------------------------------------------------------



WORKDIR /var/www/localhost/

#----------------------------------- 5. PHP MY ADMIN ---------------------------------------------
# Move start.sh from our computer inside the container
COPY ./srcs/start.sh /usr/local/bin

# Every other command in Dockerfile is executed while "building" our container
# CMD tells Docker the default command to execute when we are "running" our container
CMD bash /usr/local/bin/start.sh;

# Download phpMyAdmin by using "wget" which we installed in step 2
# At the time you do this you might need to download a different version from 5.1.0
# Try to always use the latest version
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-english.tar.gz

# Extract the downloaded compressed files and remove the ".tar" file we no longer need
RUN tar -xf phpMyAdmin-5.1.0-english.tar.gz && rm -rf phpMyAdmin-5.1.0-english.tar.gz

# Rename the downloaded folder by "phpmyadmin"
RUN mv phpMyAdmin-5.1.0-english phpmyadmin

# Copy the "config.inc.php" file we created to the same "phpmyadmin" folder
COPY ./srcs/config.inc.php phpmyadmin
#-------------------------------------------------------------------------------------------------

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp
RUN mkdir -p /var/www/localhost/wordpress

COPY ./srcs/www.conf /etc/php/7.3/fpm/pool.d/www.conf

