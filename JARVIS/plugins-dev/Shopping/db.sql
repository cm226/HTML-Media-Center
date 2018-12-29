DROP TABLE IF EXISTS SelectedIngredients;
DROP TABLE IF EXISTS SelectedMeals;
DROP TABLE IF EXISTS Ingredients;
DROP TABLE IF EXISTS Meals;


CREATE TABLE Meals (
    id MEDIUMINT NOT NULL AUTO_INCREMENT,
    meal_name CHAR(255),
    PRIMARY KEY(id)
) ENGINE = InnoDB;

CREATE TABLE Ingredients (
    id MEDIUMINT NOT NULL AUTO_INCREMENT,
    ingredient_name VARCHAR(255) ,
    store VARCHAR(255) ,
    meal_id MEDIUMINT NOT NULL,
    PRIMARY KEY(id),
    CONSTRAINT `fk_meal_id` FOREIGN KEY (meal_id) REFERENCES Meals (id) ON DELETE CASCADE ON UPDATE RESTRICT
) ENGINE = InnoDB;


CREATE TABLE SelectedIngredients(
    id MEDIUMINT NOT NULL,
    PRIMARY KEY(id),
    meal_id MEDIUMINT NOT NULL,
    CONSTRAINT `fk_ingred_selected_meal_id` FOREIGN KEY (meal_id) REFERENCES Meals (id) ON DELETE CASCADE ON UPDATE RESTRICT,
    CONSTRAINT `fk_selected_ingredient_id` FOREIGN KEY (id) REFERENCES Ingredients (id) ON DELETE CASCADE ON UPDATE RESTRICT
) ENGINE = InnoDB;

INSERT INTO Meals VALUES(null, "test_meal");
INSERT INTO Meals VALUES(null, "test_meal2");

INSERT INTO Ingredients VALUES(null, "test_ingred", "Sainsbury", 1);
INSERT INTO Ingredients VALUES(null, "test_ingred2", "Sainsbury", 1);
INSERT INTO Ingredients VALUES(null, "aldi_ingred", "Aldi", 1);

INSERT INTO Ingredients VALUES(null, "test_meal2_ingred", "Sainsbury", 2);