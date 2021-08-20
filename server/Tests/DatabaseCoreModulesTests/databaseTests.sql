-- MySQL dump 10.13  Distrib 5.5.31, for debian-linux-gnu (i686)
--
-- Host: localhost    Database: mediaserver
-- ------------------------------------------------------
-- Server version	5.5.31-0ubuntu0.12.04.2

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Album`
--

DROP TABLE IF EXISTS `Album`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Album` (
  `albumID` int(11) NOT NULL AUTO_INCREMENT,
  `albumName` varchar(20) DEFAULT NULL,
  `artistID` int(11) NOT NULL,
  `year` year(4) NOT NULL,
  `albumRating` int(2) NOT NULL,
  PRIMARY KEY (`albumID`),
  KEY `artistID` (`artistID`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Album`
--

LOCK TABLES `Album` WRITE;
/*!40000 ALTER TABLE `Album` DISABLE KEYS */;
INSERT INTO `Album` VALUES (1,'testAlbum',1,2010,1),(2,'testAlbum',1,2010,1);
/*!40000 ALTER TABLE `Album` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Artist`
--

DROP TABLE IF EXISTS `Artist`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Artist` (
  `artistID` int(11) NOT NULL AUTO_INCREMENT,
  `artistName` varchar(20) DEFAULT NULL,
  `artistRating` int(2) NOT NULL,
  `genre` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`artistID`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Artist`
--

LOCK TABLES `Artist` WRITE;
/*!40000 ALTER TABLE `Artist` DISABLE KEYS */;
INSERT INTO `Artist` VALUES (1,'testArtist1',1,'duno'),(2,'testArtist2',1,'duno');
/*!40000 ALTER TABLE `Artist` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Episode`
--

DROP TABLE IF EXISTS `Episode`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Episode` (
  `episodeID` int(11) NOT NULL AUTO_INCREMENT,
  `episodeNumber` int(11) DEFAULT NULL,
  `episodeName` varchar(256) DEFAULT NULL,
  `episodeLength` time NOT NULL,
  `episodePlayCount` int(3) NOT NULL,
  `seasonID` int(11) NOT NULL,
  `filePath` varchar(256) NOT NULL,
  PRIMARY KEY (`episodeID`),
  KEY `seasonID` (`seasonID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Episode`
--

LOCK TABLES `Episode` WRITE;
/*!40000 ALTER TABLE `Episode` DISABLE KEYS */;
/*!40000 ALTER TABLE `Episode` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Movie`
--

DROP TABLE IF EXISTS `Movie`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Movie` (
  `movieID` int(11) NOT NULL AUTO_INCREMENT,
  `movieName` varchar(20) DEFAULT NULL,
  `movieURL` varchar(256) DEFAULT NULL,
  `movieIMDB` varchar(40) NOT NULL,
  `movieLength` time NOT NULL,
  `movieGenre` varchar(40) DEFAULT NULL,
  `thumbnailURL` varchar(256) DEFAULT NULL,
  PRIMARY KEY (`movieID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Movie`
--

LOCK TABLES `Movie` WRITE;
/*!40000 ALTER TABLE `Movie` DISABLE KEYS */;
/*!40000 ALTER TABLE `Movie` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Picture`
--

DROP TABLE IF EXISTS `Picture`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Picture` (
  `picName` varchar(40) NOT NULL,
  `picURL` varchar(256) NOT NULL,
  `albumName` varchar(40) DEFAULT NULL,
  PRIMARY KEY (`picURL`),
  KEY `albumName` (`albumName`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Picture`
--

LOCK TABLES `Picture` WRITE;
/*!40000 ALTER TABLE `Picture` DISABLE KEYS */;
/*!40000 ALTER TABLE `Picture` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Picturealbum`
--

DROP TABLE IF EXISTS `Picturealbum`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Picturealbum` (
  `albumName` varchar(40) NOT NULL,
  PRIMARY KEY (`albumName`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Picturealbum`
--

LOCK TABLES `Picturealbum` WRITE;
/*!40000 ALTER TABLE `Picturealbum` DISABLE KEYS */;
/*!40000 ALTER TABLE `Picturealbum` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Playlist`
--

DROP TABLE IF EXISTS `Playlist`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Playlist` (
  `playlistName` varchar(40) NOT NULL,
  `playlistPlayCount` int(3) NOT NULL,
  PRIMARY KEY (`playlistName`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Playlist`
--

LOCK TABLES `Playlist` WRITE;
/*!40000 ALTER TABLE `Playlist` DISABLE KEYS */;
/*!40000 ALTER TABLE `Playlist` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Playlistsong`
--

DROP TABLE IF EXISTS `Playlistsong`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Playlistsong` (
  `playlistSongID` int(11) NOT NULL AUTO_INCREMENT,
  `playlistName` varchar(40) NOT NULL,
  `songID` varchar(256) DEFAULT NULL,
  PRIMARY KEY (`playlistSongID`),
  KEY `playlistName` (`playlistName`),
  KEY `songID` (`songID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Playlistsong`
--

LOCK TABLES `Playlistsong` WRITE;
/*!40000 ALTER TABLE `Playlistsong` DISABLE KEYS */;
/*!40000 ALTER TABLE `Playlistsong` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Season`
--

DROP TABLE IF EXISTS `Season`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Season` (
  `seasonID` int(11) NOT NULL AUTO_INCREMENT,
  `seriesName` varchar(40) DEFAULT NULL,
  `seriesNumber` int(11) DEFAULT NULL,
  PRIMARY KEY (`seasonID`),
  KEY `seriesName` (`seriesName`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Season`
--

LOCK TABLES `Season` WRITE;
/*!40000 ALTER TABLE `Season` DISABLE KEYS */;
/*!40000 ALTER TABLE `Season` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Series`
--

DROP TABLE IF EXISTS `Series`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Series` (
  `seriesName` varchar(40) NOT NULL,
  `seriesIMDB` int(11) NOT NULL,
  `seriesDate` year(4) NOT NULL,
  `seriesGenre` varchar(40) NOT NULL,
  PRIMARY KEY (`seriesName`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Series`
--

LOCK TABLES `Series` WRITE;
/*!40000 ALTER TABLE `Series` DISABLE KEYS */;
/*!40000 ALTER TABLE `Series` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Song`
--

DROP TABLE IF EXISTS `Song`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Song` (
  `songID` int(11) NOT NULL AUTO_INCREMENT,
  `songName` varchar(40) DEFAULT NULL,
  `albumID` int(11) NOT NULL,
  `songLength` time NOT NULL,
  `songRating` int(2) NOT NULL,
  `playCount` int(3) NOT NULL,
  `songURL` varchar(256) DEFAULT NULL,
  `dateAdded` date DEFAULT NULL,
  PRIMARY KEY (`songID`),
  KEY `albumID` (`albumID`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Song`
--

LOCK TABLES `Song` WRITE;
/*!40000 ALTER TABLE `Song` DISABLE KEYS */;
INSERT INTO `Song` VALUES (1,'testSong',1,'00:03:00',1,1,'test','0000-00-00'),(2,'testSong',1,'00:03:00',1,1,'test','0000-00-00');
/*!40000 ALTER TABLE `Song` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2013-06-03 18:11:26
