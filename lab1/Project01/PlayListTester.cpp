/* PlayListTester.cpp defines the PlayList test-methods.
 * Student Name: Melissa Van Baren (mlv49)
 * Date: 9/13/17
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "PlayListTester.h"
#include "PlayList.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
using namespace std;

void PlayListTester::runTests()
{
	cout << "\nTesting class PlayList..." << endl;
	testConstructors();
	testSearchByArtist();
	testSearchByYear();
	testSearchByTitlePhrase();
	testAddSong();
	testSave();
    cout << "All tests passed!" << endl;
}

//make explicit constructor
void PlayListTester::testConstructors()
{
	cout << "- constructors... " << flush;
	PlayList pList("testSongs.txt");
	assert(pList.getNumSongs() == 4);
	cout << " 0 " << flush;

	cout << " PASSED!" << endl;
}

void PlayListTester::testSearchByArtist()
{
	cout << "- searchByArtist()... " << flush;
	//load playlist with test songs
	PlayList pList("testSongs.txt");

	//empty case (0)
	vector<Song> searchResult = pList.searchByArtist("Cream");
	assert(searchResult.size() == 0);
	cout << " 0 " << flush;

	//case of 1
	searchResult = pList.searchByArtist("Baez");
	assert(searchResult.size() == 1);
	assert(searchResult[0].getTitle() == "Let It Be");
	cout << " 1 " << flush;

	//case of 2
	searchResult = pList.searchByArtist("Beatles");
	assert(searchResult.size() == 2);
	assert(searchResult[0].getTitle() == "Let It Be");
	assert(searchResult[1].getTitle() == "Penny Lane");
	cout << " 2 " << flush;

	cout<< " PASSED!" << endl;

}

void PlayListTester::testSearchByYear()
{
	cout << "- searchByYear()... " << flush;
	//load playlist with test songs
	PlayList pList("testSongs.txt");

	//empty case (0)
	vector<Song> searchResult = pList.searchByYear(2015);
	assert(searchResult.size() == 0);
	cout << " 0 " << flush;

	//case of 1
	searchResult = pList.searchByYear(2012);
	assert(searchResult.size() == 1);
	assert(searchResult[0].getTitle() == "Call Me Maybe");
	cout << " 1 " << flush;

	//case of 2
	searchResult = pList.searchByYear(1967);
	assert(searchResult.size() == 2);
	assert(searchResult[0].getTitle() == "Let It Be");
	assert(searchResult[1].getTitle() == "Penny Lane");
	cout << " 2 " << flush;

	cout<< " PASSED!" << endl;
}

void PlayListTester::testSearchByTitlePhrase()
{
	cout << "- searchByTitlePhrase()... " << flush;
	//load playlist with test songs
	PlayList pList("testSongs.txt");

	//empty case (0)
	vector<Song> searchResult = pList.searchByTitlePhrase("Cream");
	assert(searchResult.size() == 0);
	cout << " 0 " << flush;

	//case of 1
	searchResult = pList.searchByTitlePhrase("Call Me");
	assert(searchResult.size() == 1);
	assert(searchResult[0].getTitle() == "Call Me Maybe");
	cout << " 1 " << flush;

	//case of 1, phrase at end
	searchResult = pList.searchByTitlePhrase("Lane");
	assert(searchResult.size() == 1);
	assert(searchResult[0].getTitle() == "Penny Lane");
	cout << " 2 " << flush;

	//case of 2
	searchResult = pList.searchByTitlePhrase("Let It");
	assert(searchResult.size() == 2);
	assert(searchResult[0].getTitle() == "Let It Be");
	cout << " 3 " << flush;

	cout<< " PASSED!" << endl;
}

void PlayListTester::testAddSong()
{
	cout << "- test addSong() and removeSong()... " << endl;
	//load playlist with test songs
	PlayList pList("testSongs.txt");
	cout << " - original playlist length: " << pList.getNumSongs() << endl;

	//check addSong
	Song newSong("Believer", "Imagine Dragons", 2016);
	pList.addSong(newSong);
	cout << " - playlist length after adding song: " << pList.getNumSongs() << endl;

	//remove the song you just added
	pList.removeSong(newSong);
	cout << " - playlist length after removing song: " << pList.getNumSongs() << endl;
}

void PlayListTester::testSave()
{
	//want to view original playlist, add a song, close/open playlist and check that song is still present
	cout << "Testing Save function by adding song" << endl;

	PlayList pList("testSongs.txt"); //finding playlist

	int size = pList.getNumSongs();

	Song newSong("Believer", "Imagine Dragons", 2016); //song adding to playlist
	pList.addSong(newSong);
	pList.save();

	PlayList pList2("testSongs.txt");

	int size2 = pList2.getNumSongs();

	if (size2 > size)
	{
		cout << "PASSED!" << endl;
	}

	cout << "(removing extra song)" << endl;
	pList.removeSong(newSong); //remove new song so that can rerun tests
	pList.save();

}
