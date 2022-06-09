#! /bin/bash
MYSQLCMD="mysql -u root --skip-password"

#------------------------ setup database  ----------------------------------------

mysql_install_db --user=mysql

mysqld -u mysql --bootstrap << EOF
	FLUSH PRIVILEGES;
	CREATE DATABASE ${MARIADB_DATABASE};
	CREATE USER '${MARIADB_USER}'@'%' IDENTIFIED BY '${MARIADB_PASSWORD}';
	GRANT ALL ON ${MARIADB_DATABASE}.* TO '${MARIADB_USER}'@'%';
	FLUSH PRIVILEGES;
EOF

sed -i 's/127.0.0.1/0.0.0.0/' /etc/mysql/mariadb.conf.d/50-server.cnf
#------------------------ boot database  ----------------------------------------
mysqld_safe