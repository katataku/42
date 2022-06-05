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

# Php packages are needed to read our configuration files and properly connect all of our components together
# In case a php package is missing, we will get an error when launching php related services later
RUN apt-get -y install php-cgi php-common php-fpm php-pear php-mbstring \
						php-zip php-net-socket php-gd php-xml-util php-gettext php-mysql php-bcmath
#-------------------------------------------------------------------------------------------------

#---------------------------------- 3. Install and configure Nginx  ------------------------------
# NGINX will need a folder where it will search for everything related to our website
# We can use the "html" folder that already exists in var/www directory,
# but it's a good practice to have a separate folder for every website in case we create more than 1
RUN mkdir /var/www/localhost

# COPY copies files from the given directory on our computer to given directory inside our container.
# If a file already exists in the specified directory, it will overwrite it
# We place it inside /etc/nginx/sites-available as required per NGINX documentation
COPY srcs/localhost /etc/nginx/sites-available

# We also need to create a link between the 2 following folder to "enable" our website
RUN ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled

# For the next steps, we will be working inside /var/www/localhost directory
# To avoid writing /var/www/localhost before every command, we can change current working directory
# WORKDIR command in dockerfile changes the directory where next commands will be executed
WORKDIR /var/www/localhost/
#-------------------------------------------------------------------------------------------------

#------------------------------ 4. Add SSL protocol and autoindex --------------------------------
# SSL creates a secured channel between the web browser and the web server
#
# "openssl" command allows us to create a certificate and key ourselves
# here below is the explanation of the flags used:
# -x509 specifies a self signed certificate
# -nodes specifies that the private key wont be encrypted
# -days specifies the validity (in days) of the certificate
# -subj allows us to use the following string (and not create a separate file for it)
# The next line is personnal information, you will need to use your own
# -newkey creates a new certificate request and a new private key 
# -rsa 2018 is the standard key size (in bits)
# -keyout specifies where to save the key
# -out specifies the file name
RUN openssl req -x509 -nodes -days 30 -subj "/C=BE/ST=Belgium/L=Brussels/O=42 Network/OU=s19/CN=ysoroko" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt;
#-------------------------------------------------------------------------------------------------


#----------------------------------- 5. PHP MY ADMIN ---------------------------------------------
# Move start.sh from our computer inside the container
COPY ./srcs/start.sh ./

# Every other command in Dockerfile is executed while "building" our container
# CMD tells Docker the default command to execute when we are "running" our container
CMD bash start.sh;

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

