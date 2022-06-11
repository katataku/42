#------------------------ setup WordPress  ----------------------------------------
if ! wp core is-installed --allow-root ; then
	echo "WordPress is not installed"

	if [ ! -e ./index.php ]; then
		echo "start download WordPress"
		wp core download --allow-root
	fi

	if [ ! -e ./wp-config.php ]; then
		echo "start create config of WordPress"
		wp config create \
			--allow-root \
			--dbname=${MARIADB_DATABASE} \
			--dbuser=${MARIADB_USER} \
			--dbpass=${MARIADB_PASSWORD} \
			--dbhost=${WORDPRESS_DB_HOST}
	fi

	echo "start install WordPress"
	wp core install \
		--allow-root \
		--url=localhost \
		--title=Example \
		--admin_user=supervisor \
		--admin_password=strongpassword \
		--admin_email=info@example.com

	chown -R www-data:www-data *
	chmod -R 755 /var/www/*

	echo "finish install"
else
	echo "WordPress is already installed"
fi

#------------------------ boot WordPress  ----------------------------------------
echo "Starting pfp-fpm7.3"
php-fpm7.3 -F