DROP USER if EXISTS arsehole;
DROP DATABASE IF EXISTS arseholeDB;

CREATE DATABASE arseholeDB;
CREATE USER 'arsehole' IDENTIFIED BY 'pw';
GRANT USAGE ON *.* TO 'arsehole'@'%' IDENTIFIED BY 'pw';
GRANT ALL privileges ON `arseholeDB`.* TO 'arsehole'@'%';
FLUSH PRIVILEGES;