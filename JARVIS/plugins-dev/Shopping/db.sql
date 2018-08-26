DROP TABLE IF EXISTS Ingredients;
DROP TABLE IF EXISTS Meals;

CREATE TABLE Meals (
    id MEDIUMINT NOT NULL AUTO_INCREMENT,
    meal_name CHAR(255),
    PRIMARY KEY(id)
);

CREATE TABLE Ingredients (
    id MEDIUMINT NOT NULL AUTO_INCREMENT,
    ingredient_name VARCHAR(255) ,
    store VARCHAR(255) ,
    meal_id MEDIUMINT,
    PRIMARY KEY(id),
    CONSTRAINT `fk_meal_id`
		FOREIGN KEY (meal_id) REFERENCES Meals (id)
);

INSERT INTO Meals VALUES(null, "test_meal");
INSERT INTO Ingredients VALUES(null, "test_ingred", "store", 1);