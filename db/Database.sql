drop table Song;
drop table PlaylistSong;
drop table Playlist;
drop table Album;
drop table Artist;
drop table Movie;
drop table Episode;
drop table Season;
drop table Series;

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
songName VARCHAR(40) PRIMARY KEY,
albumName VARCHAR(20) NOT NULL,
songLength TIME NOT NULL,
songRating INT(2) NOT NULL,
playCount INT(3) NOT NULL,
songURL VARCHAR(256),
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
songName VARCHAR(40),
FOREIGN KEY (playlistName) REFERENCES Playlist (playlistName),
FOREIGN KEY (songName) REFERENCES Song (songName)
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
seriesDate DATE NOT NULL,
seriesGenre VARCHAR(40) NOT NULL
);

CREATE TABLE Season
(
seasonID INT PRIMARY KEY AUTO_INCREMENT,
seriesName VARCHAR(40),
FOREIGN KEY (seriesName) REFERENCES Series (seriesName)
);

CREATE TABLE Episode
(
episodeName VARCHAR(40) PRIMARY KEY,
episodeLength TIME NOT NULL,
episodePlayCount INT(3) NOT NULL,
seasonID INT NOT NULL,
FOREIGN KEY (seasonID) REFERENCES Season (seasonID)
);

insert into Artist values('NickleBack',10,'Rock');
insert into Artist values('Avenged Sevenfold',10,'Metal');
insert into Artist values('3 Inches of blood',7,'Metal/Screemo');
insert into Artist values('Bon Jovie',5,'Rock');
insert into Artist values('breed 77',4,'Rock');
insert into Artist values('Iron Maiden',8,'Metal');

insert into Album values('All the Right Reasons','NickleBack',2007,10);
insert into Album values('The State','NickleBack',1900,5);
insert into Album values('Bat Country','Avenged Sevenfold',2007,10);
insert into Album values('Edward The Great','Iron Maiden',2007,10);
insert into Album values('The Trooper','Iron Maiden',2007,10);

insert into Song values('Run To the Hills','Edward The Great','00:03:10',9,0,'../public/mix/Music/breakingenjamin/06 - Breaking Benjamin - Until The End.mp3');
insert into Song values('animals','All the Right Reasons','00:03:10',9,0,'../public/mix/Music/Nickelback/All the Right Reasons/animals.mp3');
insert into Song values('Run To the Hills','Edward The Great','00:03:10',9,0,'../public/mix/Music/breakingenjamin/06 - Breaking Benjamin - Until The End.mp3');
insert into Song values('Run To the Hills','Edward The Great','00:03:10',9,0,'../public/mix/Music/breakingenjamin/06 - Breaking Benjamin - Until The End.mp3');



