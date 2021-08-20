DROP USER if EXISTS Server;
DROP DATABASE IF EXISTS ServerDB;

CREATE DATABASE ServerDB;
CREATE USER 'Server' IDENTIFIED BY 'pw';
GRANT USAGE ON *.* TO 'Server'@'localhost' IDENTIFIED BY 'pw';
GRANT ALL privileges ON `ServerDB`.* TO 'Server'@'localhost';
FLUSH PRIVILEGES;