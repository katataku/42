#! /bin/bash

#------------------------ setup database  ----------------------------------------
if [ ! -d /var/lib/mysql/mysql ]; then
	echo "MySQL is not installed"
	echo "start install MySQL"

	mysql_install_db --user=mysql

	mysqld -u mysql --bootstrap << EOF
		FLUSH PRIVILEGES;
		CREATE DATABASE ${MARIADB_DATABASE};
		CREATE USER '${MARIADB_USER}'@'%' IDENTIFIED BY '${MARIADB_PASSWORD}';
		GRANT ALL ON ${MARIADB_DATABASE}.* TO '${MARIADB_USER}'@'%';
		FLUSH PRIVILEGES;
EOF

	sed -i 's/127.0.0.1/0.0.0.0/' /etc/mysql/mariadb.conf.d/50-server.cnf
else
	echo "MySQL is already installed"
fi

#------------------------ boot database  ----------------------------------------

echo "Starting MySQL"
mysqld_safe