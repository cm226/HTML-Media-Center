DROP USER if EXISTS Arsehole;
DROP DATABASE IF EXISTS ArseholeDB;

CREATE DATABASE ArseholeDB;
CREATE USER 'Arsehole' IDENTIFIED BY 'pw';
GRANT USAGE ON *.* TO 'Arsehole'@'localhost' IDENTIFIED BY 'pw';
GRANT ALL privileges ON `ArseholeDB`.* TO 'Arsehole'@'localhost';
FLUSH PRIVILEGES;