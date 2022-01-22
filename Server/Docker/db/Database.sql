DROP USER if EXISTS Server;
DROP DATABASE IF EXISTS ServerDB;

CREATE DATABASE ServerDB;
CREATE USER 'Server' IDENTIFIED BY 'pw';
GRANT USAGE ON *.* TO 'Server'@'localhost' IDENTIFIED BY 'pw';
GRANT ALL privileges ON `ServerDB`.* TO 'Server'@'localhost';
FLUSH PRIVILEGES;

USE ServerDB;

DROP TABLE IF EXISTS Sensors;

CREATE TABLE Sensors (
    id MEDIUMINT NOT NULL AUTO_INCREMENT,
    sensor_name VARCHAR(255),
    PRIMARY KEY(id)
) ENGINE = InnoDB;

DROP TABLE IF EXISTS SelectedIngredients;
DROP TABLE IF EXISTS SelectedMeals;
DROP TABLE IF EXISTS Ingredients;
DROP TABLE IF EXISTS Meals;
DROP TABLE IF EXISTS Extras;


CREATE TABLE Meals (
    id MEDIUMINT NOT NULL AUTO_INCREMENT,
    meal_name CHAR(255),
    selected_meal BOOLEAN,
    PRIMARY KEY(id)
) ENGINE = InnoDB;

CREATE TABLE Ingredients (
    id MEDIUMINT NOT NULL AUTO_INCREMENT,
    ingredient_name VARCHAR(255) ,
    store VARCHAR(255) ,
    meal_id MEDIUMINT NOT NULL,
    selected_ingred BOOLEAN,
    PRIMARY KEY(id),
    CONSTRAINT `fk_meal_id` FOREIGN KEY (meal_id) REFERENCES Meals (id) ON DELETE CASCADE ON UPDATE RESTRICT
) ENGINE = InnoDB;

CREATE TABLE Extras (
    id MEDIUMINT NOT NULL AUTO_INCREMENT,
    ingredient_name VARCHAR(255) ,
    store VARCHAR(255),
    PRIMARY KEY(id)
) ENGINE = InnoDB;