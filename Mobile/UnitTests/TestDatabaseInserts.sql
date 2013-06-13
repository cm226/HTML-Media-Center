INSERT INTO Artist VALUES(NULL, 'TestArtist1', 10,'TestGenra1');
INSERT INTO Artist VALUES(NULL, 'TestArtist2', 9,'TestGenra2');
INSERT INTO Artist VALUES(NULL, 'TestArtist3', 8,'TestGenra3');


ALTER TABLE `Album` AUTO_INCREMENT = 1;
INSERT INTO Album VALUES(NULL, 'testAlbum1', 1, 2012, 10);
INSERT INTO Album VALUES(NULL, 'testAlbum2', 1, 2012, 10);
INSERT INTO Album VALUES(NULL, 'testAlbum3', 2, 2012, 10);

INSERT INTO Song VALUES(NULL, 'song1', 1, '00:03:00',1,1,'Nickelback/All the Right Reasons/animals.mp3', '');
INSERT INTO Song VALUES(NULL, 'song2', 1, '00:03:00',1,1,'Nickelback/All the Right Reasons/animals.mp3', '');
INSERT INTO Song VALUES(NULL, 'song3', 1, '00:03:00',1,1,'Nickelback/All the Right Reasons/animals.mp3', '');

INSERT INTO Song VALUES(NULL, 'song1', 2, '00:03:00',1,1,'Nickelback/All the Right Reasons/animals.mp3', '');
INSERT INTO Song VALUES(NULL, 'song2', 2, '00:03:00',1,1,'Nickelback/All the Right Reasons/animals.mp3', '');
INSERT INTO Song VALUES(NULL, 'song3', 2, '00:03:00',1,1,'Nickelback/All the Right Reasons/animals.mp3', '');


INSERT INTO Song VALUES(NULL, 'song1', 3, '00:03:00',1,1,'Nickelback/All the Right Reasons/animals.mp3', '');
INSERT INTO Song VALUES(NULL, 'song2', 3, '00:03:00',1,1,'Nickelback/All the Right Reasons/animals.mp3', '');
INSERT INTO Song VALUES(NULL, 'song3', 3, '00:03:00',1,1,'Nickelback/All the Right Reasons/animals.mp3', '');
