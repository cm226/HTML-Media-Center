drop table Song;
drop table PlaylistSong;
drop table Playlist;
drop table Album;
drop table Artist;
drop table Movie;
drop table Episode;
drop table Season;
drop table Series;
drop table Picture;
drop table PictureAlbum;

drop procedure if exists OrganiseEpisodes;

CREATE TABLE Artist
(
artistName VARCHAR(20) PRIMARY KEY,
artistRating INT(2) NOT NULL,
genre VARCHAR(20)
);

CREATE TABLE Album
(
albumName VARCHAR(20) PRIMARY KEY,
artistName VARCHAR(20) NOT NULL,
year YEAR NOT NULL,
albumRating INT(2) NOT NULL,
FOREIGN KEY (artistName) REFERENCES Artist (artistName)
);

CREATE TABLE Song
(
songName VARCHAR(40),
albumName VARCHAR(20) NOT NULL,
songLength TIME NOT NULL,
songRating INT(2) NOT NULL,
playCount INT(3) NOT NULL,
songURL VARCHAR(256) PRIMARY KEY,
FOREIGN KEY (albumName) REFERENCES Album (albumName)
);

CREATE TABLE Playlist
(
playlistName VARCHAR(40) PRIMARY KEY,
playlistPlayCount INT(3) NOT NULL
);

CREATE TABLE PlaylistSong
(
playlistSongID INT PRIMARY KEY AUTO_INCREMENT,
playlistName VARCHAR(40) NOT NULL,
songID VARCHAR(40),
FOREIGN KEY (playlistName) REFERENCES Playlist (playlistName),
FOREIGN KEY (songID) REFERENCES Song (songURL)
);

CREATE TABLE Movie
(
movieName VARCHAR(20) PRIMARY KEY,
movieIMDB VARCHAR(40) NOT NULL,
movieLength TIME NOT NULL,
movieGenre VARCHAR(40)
);

CREATE TABLE Series
(
seriesName VARCHAR(40) PRIMARY KEY,
seriesIMDB VARCHAR(40) NOT NULL,
seriesDate YEAR NOT NULL,
seriesGenre VARCHAR(40) NOT NULL
);

CREATE TABLE Season
(
seasonID INT PRIMARY KEY AUTO_INCREMENT,
seriesName VARCHAR(40),
seriesNumber INT,
FOREIGN KEY (seriesName) REFERENCES Series (seriesName)
);

CREATE TABLE Episode
(
episodeName VARCHAR(40) PRIMARY KEY,
episodeLength TIME NOT NULL,
episodePlayCount INT(3) NOT NULL,
seasonID INT NOT NULL,
filePath VARCHAR(256) NOT NULL,
episodeNumber INT NOT NULL,
FOREIGN KEY (seasonID) REFERENCES Season (seasonID)
);

CREATE TABLE PictureAlbum
(
	albumName VARCHAR(40) PRIMARY KEY	
);

CREATE TABLE Picture
(
	picName VARCHAR(40) NOT NULL,
	picURL VARCHAR(256) PRIMARY KEY,
	albumName VARCHAR(40),
	FOREIGN KEY (albumName) REFERENCES PictureAlbum (albumName)
);


/*
DELIMITER $$ 
CREATE PROCEDURE OrganiseEpisodes(seriesName varchar(40))
BEGIN
	DECLARE numOfSeasons INT Default 0;
	SET numOfSeasons = 
END$$

DELIMITER ;

--finish this later its a proceedure to organise the eppisedes into collumns for each season
*/






