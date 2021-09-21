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


INSERT INTO Meals VALUES(null, "fish",0);
INSERT INTO Meals VALUES(null, "roast chicken",0);
INSERT INTO Meals VALUES(null, "roast beef",0);
INSERT INTO Meals VALUES(null, "toad in the hole",0);
INSERT INTO Meals VALUES(null, "lasagna",0);
INSERT INTO Meals VALUES(null, "leak and potato soup",0);
INSERT INTO Meals VALUES(null, "broth",0);
INSERT INTO Meals VALUES(null, "sweet potato n carrot",0);
INSERT INTO Meals VALUES(null, "korma",0);
INSERT INTO Meals VALUES(null, "tofu",0);
INSERT INTO Meals VALUES(null, "salmon pasta",0);
INSERT INTO Meals VALUES(null, "teryaki salmon",0);
INSERT INTO Meals VALUES(null, "m&s chicken",0);
INSERT INTO Meals VALUES(null, "haggis burreto",0);
INSERT INTO Meals VALUES(null, "mince burreto",0);
INSERT INTO Meals VALUES(null, "cheesy pasta",0);
INSERT INTO Meals VALUES(null, "brocli soup",0);
INSERT INTO Meals VALUES(null, "chicken n sweetcorn soup",0);

INSERT INTO Ingredients VALUES(null, "fish", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'fish') ,0);
INSERT INTO Ingredients VALUES(null, "spring onion", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'fish') ,0);
INSERT INTO Ingredients VALUES(null, "ginger", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'fish') ,0);

INSERT INTO Ingredients VALUES(null, "chicken", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'roast chicken') ,0);
INSERT INTO Ingredients VALUES(null, "parsnips", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'roast chicken') ,0);
INSERT INTO Ingredients VALUES(null, "carrots", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'roast chicken') ,0);
INSERT INTO Ingredients VALUES(null, "collyflour", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'roast chicken') ,0);
INSERT INTO Ingredients VALUES(null, "trex", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'roast chicken'),0 );
INSERT INTO Ingredients VALUES(null, "cheese", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'roast chicken') ,0);
INSERT INTO Ingredients VALUES(null, "potatos", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'roast chicken') ,0);
INSERT INTO Ingredients VALUES(null, "yorkies", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'roast chicken'),0 );

INSERT INTO Ingredients VALUES(null, "beef", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'roast beef') ,0);
INSERT INTO Ingredients VALUES(null, "wonky veg", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'roast beef') ,0);
INSERT INTO Ingredients VALUES(null, "pastry", "Sainsbry", (SELECT id FROM Meals WHERE meal_name = 'roast beef') ,0);
INSERT INTO Ingredients VALUES(null, "mushrooms", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'roast beef'),0 );
INSERT INTO Ingredients VALUES(null, "sausages", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'roast beef') ,0);

INSERT INTO Ingredients VALUES(null, "sausages", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'toad in the hole') ,0);
INSERT INTO Ingredients VALUES(null, "onion", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'toad in the hole') ,0);
INSERT INTO Ingredients VALUES(null, "eggs", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'toad in the hole') ,0);
INSERT INTO Ingredients VALUES(null, "flour", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'toad in the hole') ,0);

INSERT INTO Ingredients VALUES(null, "mince", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'lasagna') ,0);
INSERT INTO Ingredients VALUES(null, "lasagna sauce", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'lasagna') ,0);
INSERT INTO Ingredients VALUES(null, "brocli", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'lasagna'),0 );
INSERT INTO Ingredients VALUES(null, "mushroom", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'lasagna'),0 );
INSERT INTO Ingredients VALUES(null, "cheese", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'lasagna') ,0);
INSERT INTO Ingredients VALUES(null, "lasagna strips", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'lasagna'),0 );

INSERT INTO Ingredients VALUES(null, "leeks", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'leak and potato soup'),0 );
INSERT INTO Ingredients VALUES(null, "potatos", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'leak and potato soup'),0 );
INSERT INTO Ingredients VALUES(null, "cream", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'leak and potato soup') ,0);

INSERT INTO Ingredients VALUES(null, "carrots", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'broth') ,0);
INSERT INTO Ingredients VALUES(null, "leeks", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'broth') ,0);
INSERT INTO Ingredients VALUES(null, "broth mix", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'broth'),0 );
INSERT INTO Ingredients VALUES(null, "kale", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'broth') ,0);
INSERT INTO Ingredients VALUES(null, "suide", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'broth') ,0);

INSERT INTO Ingredients VALUES(null, "sweet potato", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'sweet potato n carrot') ,0);
INSERT INTO Ingredients VALUES(null, "carrots", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'sweet potato n carrot') ,0);

INSERT INTO Ingredients VALUES(null, "kormal paste", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'korma'),0 );
INSERT INTO Ingredients VALUES(null, "cream", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'korma') ,0);

INSERT INTO Ingredients VALUES(null, "mince", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'tofu'),0 );
INSERT INTO Ingredients VALUES(null, "spring onion", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'tofu'),0 );
INSERT INTO Ingredients VALUES(null, "corn flour", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'tofu') ,0);
INSERT INTO Ingredients VALUES(null, "soy sauce", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'tofu') ,0);
INSERT INTO Ingredients VALUES(null, "seseme oil", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'tofu'),0 );

INSERT INTO Ingredients VALUES(null, "salmon", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'salmon pasta') ,0);
INSERT INTO Ingredients VALUES(null, "whole grain pasta", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'salmon pasta') ,0);
INSERT INTO Ingredients VALUES(null, "peas", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'salmon pasta') ,0);
INSERT INTO Ingredients VALUES(null, "cream freish", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'salmon pasta') ,0);
INSERT INTO Ingredients VALUES(null, "shallots", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'salmon pasta') ,0);

INSERT INTO Ingredients VALUES(null, "salmon", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'teryaki salmon') ,0);
INSERT INTO Ingredients VALUES(null, "soy sauce", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'teryaki salmon') ,0);
INSERT INTO Ingredients VALUES(null, "egg noodals", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'teryaki salmon'),0 );
INSERT INTO Ingredients VALUES(null, "syrup", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'teryaki salmon') ,0);

INSERT INTO Ingredients VALUES(null, "chicken", "M&S", (SELECT id FROM Meals WHERE meal_name = 'm&s chicken'),0 );
INSERT INTO Ingredients VALUES(null, "baby potatos", "M&S", (SELECT id FROM Meals WHERE meal_name = 'm&s chicken'),0 );
INSERT INTO Ingredients VALUES(null, "mayo", "M&S", (SELECT id FROM Meals WHERE meal_name = 'm&s chicken') ,0);
INSERT INTO Ingredients VALUES(null, "spring onion", "M&S", (SELECT id FROM Meals WHERE meal_name = 'm&s chicken'),0 );
INSERT INTO Ingredients VALUES(null, "frozen rice", "M&S", (SELECT id FROM Meals WHERE meal_name = 'm&s chicken') ,0);

INSERT INTO Ingredients VALUES(null, "haggis", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'haggis burreto'),0 );
INSERT INTO Ingredients VALUES(null, "wraps", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'haggis burreto') ,0);
INSERT INTO Ingredients VALUES(null, "avacado", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'haggis burreto') ,0);
INSERT INTO Ingredients VALUES(null, "tomato", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'haggis burreto') ,0);
INSERT INTO Ingredients VALUES(null, "salsa", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'haggis burreto'),0 );
INSERT INTO Ingredients VALUES(null, "black beans", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'haggis burreto') ,0);

INSERT INTO Ingredients VALUES(null, "mince", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'mince burreto') ,0);
INSERT INTO Ingredients VALUES(null, "wraps", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'mince burreto'),0 );
INSERT INTO Ingredients VALUES(null, "avacado", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'mince burreto') ,0);
INSERT INTO Ingredients VALUES(null, "tomato", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'mince burreto') ,0);
INSERT INTO Ingredients VALUES(null, "salsa", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'mince burreto') ,0);
INSERT INTO Ingredients VALUES(null, "black beans", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'mince burreto'),0 );

INSERT INTO Ingredients VALUES(null, "cheese", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'cheesy pasta') ,0);
INSERT INTO Ingredients VALUES(null, "pasta", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'cheesy pasta') ,0);
INSERT INTO Ingredients VALUES(null, "pepper", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'cheesy pasta') ,0);
INSERT INTO Ingredients VALUES(null, "mushrooms", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'cheesy pasta'),0 );
INSERT INTO Ingredients VALUES(null, "garlic", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'cheesy pasta'),0 );
INSERT INTO Ingredients VALUES(null, "onion", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'cheesy pasta') ,0);
INSERT INTO Ingredients VALUES(null, "cooked meats", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'cheesy pasta') ,0);

INSERT INTO Ingredients VALUES(null, "brocli", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'brocli soup') ,0);
INSERT INTO Ingredients VALUES(null, "cream", "Aldi", (SELECT id FROM Meals WHERE meal_name = 'brocli soup') ,0);
INSERT INTO Ingredients VALUES(null, "onion", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'brocli soup'),0 );

# what else does this need?
INSERT INTO Ingredients VALUES(null, "sweetcorn", "Sainsbury", (SELECT id FROM Meals WHERE meal_name = 'chicken n sweetcorn soup') ,0);







