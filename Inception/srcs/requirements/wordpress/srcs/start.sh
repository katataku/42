
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
chmod -R 755 /var/www/*

echo "finish setup"

php-fpm7.3 -F