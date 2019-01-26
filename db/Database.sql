DROP USER if EXISTS arsehole;
DROP DATABASE IF EXISTS arseholeDB;

CREATE DATABASE arseholeDB;
CREATE USER 'arsehole' IDENTIFIED BY 'pw';
GRANT USAGE ON *.* TO 'arsehole'@'localhost' IDENTIFIED BY 'pw';
GRANT ALL privileges ON `arseholeDB`.* TO 'arsehole'@'localhost';
FLUSH PRIVILEGES;