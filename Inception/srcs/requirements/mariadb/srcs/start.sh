#! /bin/bash
MYSQLCMD="mysql -u root --skip-password"

#------------------------ setup database  ----------------------------------------

service mysql start

sleep 1;

echo "CREATE USER '${MARIADB_USER}'@'%' IDENTIFIED BY 'hogehogePASS'"| ${MYSQLCMD};
echo "GRANT ALL ON *.* TO 'hogehogeID'@'%'"|  ${MYSQLCMD};
echo "CREATE DATABASE wordpress;" |  ${MYSQLCMD};
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" |  ${MYSQLCMD};
echo "FLUSH PRIVILEGES;" |  ${MYSQLCMD};
echo "update mysql.user set plugin='' where user='root';" |  ${MYSQLCMD};

service mysql stop

#------------------------ boot database  ----------------------------------------
mysql_install_db --user=mysql
mysqld_safe