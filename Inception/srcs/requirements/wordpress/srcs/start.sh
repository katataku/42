# Start up PHP
service php7.3-fpm start;

wp core download --allow-root

wp config create \
	--allow-root \
	--dbname=${MARIADB_DATABASE} \
	--dbuser=${MARIADB_USER} \
	--dbpass=${MARIADB_PASSWORD} \
	--dbhost=${WORDPRESS_DB_HOST}
echo "finish config"

wp core install \
	--allow-root \
	--url=localhost \
	--title=Example \
	--admin_user=supervisor \
	--admin_password=strongpassword \
	--admin_email=info@example.com

chown -R www-data:www-data *
chown -R www-data:www-data /var/www/localhost
chmod -R 755 /var/www/*

echo "finish setup"
# At this point the commands will be executed once and the server will shut down.
# We need to be able to keep our server running.
# There are multiple ways to achieve this, but here I will use a kind of a lazy solution of
# executing "sleep infinity" command which will simply keep our server running until we press CTRL+C
# in the terminal
sleep infinity

# Please note that since "sleep infinity" is executed while running our container,
# the "docker run" flags "-it" (= terminal mode with a "pretty" format) are not going to do anything anymore.
# If you still want to run your container in terminal mode, you can remove the "sleep infinity" command
# or simply replace "sleep infinity" with "bash" command