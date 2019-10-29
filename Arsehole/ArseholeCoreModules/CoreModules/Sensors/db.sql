DROP TABLE IF EXISTS Sensors;

CREATE TABLE Sensors (
    id MEDIUMINT NOT NULL AUTO_INCREMENT,
    sensor_name VARCHAR(255),
    PRIMARY KEY(id)
) ENGINE = InnoDB;

INSERT INTO Sensors VALUES (null, 'bedroom');