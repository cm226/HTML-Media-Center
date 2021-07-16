-- MySQL dump 10.16  Distrib 10.1.41-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: ArseholeDB
-- ------------------------------------------------------
-- Server version	10.1.41-MariaDB-0ubuntu0.18.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Current Database: `ArseholeDB`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `ArseholeDB` /*!40100 DEFAULT CHARACTER SET utf8mb4 */;

USE `ArseholeDB`;

--
-- Table structure for table `Extras`
--

DROP TABLE IF EXISTS `Extras`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Extras` (
  `id` mediumint(9) NOT NULL AUTO_INCREMENT,
  `ingredient_name` varchar(255) DEFAULT NULL,
  `store` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Extras`
--

LOCK TABLES `Extras` WRITE;
/*!40000 ALTER TABLE `Extras` DISABLE KEYS */;
/*!40000 ALTER TABLE `Extras` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Ingredients`
--

DROP TABLE IF EXISTS `Ingredients`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Ingredients` (
  `id` mediumint(9) NOT NULL AUTO_INCREMENT,
  `ingredient_name` varchar(255) DEFAULT NULL,
  `store` varchar(255) DEFAULT NULL,
  `meal_id` mediumint(9) NOT NULL,
  `selected_ingred` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_meal_id` (`meal_id`),
  CONSTRAINT `fk_meal_id` FOREIGN KEY (`meal_id`) REFERENCES `Meals` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=81 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Ingredients`
--

LOCK TABLES `Ingredients` WRITE;
/*!40000 ALTER TABLE `Ingredients` DISABLE KEYS */;
INSERT INTO `Ingredients` VALUES (1,'fish','Sainsbury',1,1),(2,'spring onion','Aldi',1,0),(3,'ginger','Sainsbury',1,0),(4,'chicken','Aldi',2,0),(5,'parsnips','Aldi',2,0),(6,'carrots','Aldi',2,0),(7,'collyflour','Sainsbury',2,0),(8,'trex','Sainsbury',2,0),(9,'cheese','Sainsbury',2,0),(10,'potatos','Aldi',2,0),(11,'yorkies','Sainsbury',2,0),(12,'beef','Aldi',3,0),(13,'wonky veg','Aldi',3,0),(14,'pastry','Sainsbry',3,0),(15,'mushrooms','Aldi',3,0),(16,'sausages','Sainsbury',3,0),(17,'sausages','Sainsbury',4,0),(18,'onion','Sainsbury',4,0),(19,'eggs','Sainsbury',4,0),(20,'flour','Sainsbury',4,0),(21,'mince','Aldi',5,0),(22,'lasagna sauce','Sainsbury',5,0),(23,'brocli','Aldi',5,0),(24,'mushroom','Aldi',5,0),(25,'cheese','Aldi',5,0),(26,'lasagna strips','Aldi',5,0),(27,'leeks','Aldi',6,0),(28,'potatos','Aldi',6,0),(29,'cream','Aldi',6,0),(30,'carrots','Aldi',7,0),(31,'leeks','Aldi',7,0),(32,'broth mix','Sainsbury',7,0),(33,'kale','Aldi',7,0),(34,'suide','Aldi',7,0),(35,'sweet potato','Aldi',8,0),(36,'carrots','Aldi',8,0),(37,'kormal paste','Sainsbury',9,0),(38,'cream','Aldi',9,0),(39,'mince','Aldi',10,0),(40,'spring onion','Aldi',10,0),(41,'corn flour','Aldi',10,0),(42,'soy sauce','Aldi',10,0),(43,'seseme oil','Aldi',10,0),(44,'salmon','Sainsbury',11,0),(45,'whole grain pasta','Sainsbury',11,0),(46,'peas','Aldi',11,0),(47,'cream freish','Sainsbury',11,0),(48,'shallots','Sainsbury',11,0),(49,'salmon','Sainsbury',12,0),(50,'soy sauce','Aldi',12,0),(51,'egg noodals','Sainsbury',12,0),(52,'syrup','Sainsbury',12,0),(53,'chicken','M&S',13,0),(54,'baby potatos','M&S',13,0),(55,'mayo','M&S',13,0),(56,'spring onion','M&S',13,0),(57,'frozen rice','M&S',13,0),(58,'haggis','Sainsbury',14,0),(59,'wraps','Sainsbury',14,0),(60,'avacado','Aldi',14,0),(61,'tomato','Aldi',14,0),(62,'salsa','Sainsbury',14,0),(63,'black beans','Sainsbury',14,0),(64,'mince','Aldi',15,0),(65,'wraps','Sainsbury',15,0),(66,'avacado','Aldi',15,0),(67,'tomato','Aldi',15,0),(68,'salsa','Sainsbury',15,0),(69,'black beans','Sainsbury',15,0),(70,'cheese','Sainsbury',16,0),(71,'pasta','Sainsbury',16,0),(72,'pepper','Aldi',16,0),(73,'mushrooms','Aldi',16,0),(74,'garlic','Aldi',16,0),(75,'onion','Aldi',16,0),(76,'cooked meats','Aldi',16,0),(77,'brocli','Aldi',17,0),(78,'cream','Aldi',17,0),(79,'onion','Sainsbury',17,0),(80,'sweetcorn','Sainsbury',18,0);
/*!40000 ALTER TABLE `Ingredients` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Meals`
--

DROP TABLE IF EXISTS `Meals`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Meals` (
  `id` mediumint(9) NOT NULL AUTO_INCREMENT,
  `meal_name` char(255) DEFAULT NULL,
  `selected_meal` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Meals`
--

LOCK TABLES `Meals` WRITE;
/*!40000 ALTER TABLE `Meals` DISABLE KEYS */;
INSERT INTO `Meals` VALUES (1,'fish',0),(2,'roast chicken',0),(3,'roast beef',0),(4,'toad in the hole',0),(5,'lasagna',0),(6,'leak and potato soup',0),(7,'broth',0),(8,'sweet potato n carrot',0),(9,'korma',0),(10,'tofu',0),(11,'salmon pasta',0),(12,'teryaki salmon',0),(13,'m&s chicken',0),(14,'haggis burreto',0),(15,'mince burreto',0),(16,'cheesy pasta',0),(17,'brocli soup',0),(18,'chicken n sweetcorn soup',0);
/*!40000 ALTER TABLE `Meals` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-11-14 12:31:54
