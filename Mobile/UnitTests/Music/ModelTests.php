<?php
require '../../library/sqlquery.class.php';
require '../../library/model.class.php';
require '../../application/models/music.php';
require '../../config/config.php';

class ModelTests extends PHPUnit_Framework_TestCase
{

	public function testViewAll()
    {
		$musicModel = new Music(DB_HOST,DB_USER,DB_PASSWORD,'mediaunittestdatabase');
		
		$viewAllResult = $musicModel->viewAll();
        $this->assertEquals(3, count($viewAllResult));
		
		$artistNames = array($viewAllResult[0]['Artist']['artistName'],
							$viewAllResult[1]['Artist']['artistName'],
							$viewAllResult[2]['Artist']['artistName']);
							
		$this->assertContains("TestArtist1", $artistNames);
		$this->assertContains("TestArtist2", $artistNames);
		$this->assertContains("TestArtist3", $artistNames);
		
		foreach ($viewAllResult as $artist)
		{
			if($artist['Artist']['artistName'] == "TestArtist1")
				$this->assertEquals(1, $artist['Artist']['artistID']);
			
			if($artist['Artist']['artistName'] == "TestArtist2")
				$this->assertEquals(2, $artist['Artist']['artistID']);
			
			if($artist['Artist']['artistName'] == "TestArtist3")
				$this->assertEquals(3, $artist['Artist']['artistID']);
		}
		
		return $musicModel;
    }
	
	public function testGetArtistsAlbumsTestBasic()
	{	
	
		$musicModel = new Music(DB_HOST,DB_USER,DB_PASSWORD,'mediaunittestdatabase');
		$artistsSongsResult = $musicModel->getArtistsAlbums(1);
		$this->assertEquals(2, count($artistsSongsResult));
		
		$albumNames = array($artistsSongsResult[0]['Album']['albumName'],
							$artistsSongsResult[1]['Album']['albumName']);
							
		$this->assertContains("testAlbum1", $albumNames);
		$this->assertContains("testAlbum2", $albumNames);
		
		foreach ($artistsSongsResult as $album)
		{
			if($album['Album']['albumName'] == "testAlbum1")
				$this->assertEquals(1, $album['Album']['albumID']);
				
			if($album['Album']['albumName'] == "testAlbum2")
				$this->assertEquals(2, $album['Album']['albumID']);
		}
	}
	
	public function testGetArtistsAlbumsTestNoAlbums()
	{	
	
		$musicModel = new Music(DB_HOST,DB_USER,DB_PASSWORD,'mediaunittestdatabase');
		$artistsSongsResult = $musicModel->getArtistsAlbums(3);
		$this->assertEquals(0, count($artistsSongsResult));
	}
	
	
	
	
	
}
?>
