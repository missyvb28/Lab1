/* PlayListApp.cpp defines the class PlayListApp
 * Student Name: Melissa Van Baren
 * Date: 9/13/17
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */
#include "PlayListApp.h"
#include "PlayListTester.h"
#include "PlayList.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
using namespace std;

//provides the menu
PlayListApp::PlayListApp()
{

}

void PlayListApp::menu() const
{
	PlayListApp Application;
	PlayList pList("testSongs.txt");
	vector<Song> foundSongs;
	string separator;
	int selector;

	cout << "Playlist Settings..." << endl;

	while (true)
	{
		cout << "Press to enter:" << endl
			 << "1 - Search by Title" << endl
			 << "2 - Search by Artist" << endl
			 << "3 - Search by Year" << endl
			 << "4 - Add Song" << endl
			 << "5 - Remove Song" << endl
			 << "6 - Save Playlist" << endl
			 << "0 - Quit" << endl;

		cin >> selector;
		getline(cin, separator);

		//search by title
		if (selector == 1)
		{
			cout << "Please enter title:" << endl;
			string Title;
			cin >> Title;
			getline(cin, separator);
			foundSongs = pList.searchByTitlePhrase(Title);
			Application.printSongs(foundSongs);
		}

		//search by artist
		else if (selector == 2)
		{
			cout << "Please enter artist:" << endl;
			string Artist;
			cin >> Artist;
			getline(cin, separator);
			foundSongs = pList.searchByArtist(Artist);
			Application.printSongs(foundSongs);
		}

		//search by year
		else if (selector == 3)
		{
			cout << "Please enter year:" << endl;
			unsigned int Year;
			string yearString;
			getline(cin, yearString);
			Year = atoi(yearString.c_str() );
			foundSongs = pList.searchByYear(Year);
			Application.printSongs(foundSongs);
		}

		//add song
		else if (selector == 4)
		{
			string myTitle;
			string myArtist;
			string yearString;
			int myYear;

			cout << "Please enter..." << endl;
			cout << "Title:" << flush;
			getline(cin, myTitle);
			cout << "Artist:" << flush;
			getline(cin, myArtist);
			cout << "Year:" << flush;
			getline(cin, yearString);
			myYear = atoi(yearString.c_str() );

			Song newSong(myTitle, myArtist, myYear);
			pList.addSong(newSong);

		}

		//remove song
		else if (selector == 5)
		{
			string songTitle;
			string songArtist;
			string yearString;
			unsigned int songYear;

			cout << "Please enter..." << endl;
			cout << "Title:" << flush;
			getline(cin, songTitle);
			cout << "Artist:" << flush;
			getline(cin, songArtist);
			cout << "Year:" << flush;
			getline(cin, yearString);
			songYear = atoi(yearString.c_str() );

			Song aSong(songTitle, songArtist, songYear);
			pList.removeSong(aSong);
		}

		//save
		else if (selector == 6)
		{
			pList.save();
		}

		//quit
		else if (selector == 0)
		{
			return;
		}

		else
		{
			cout << "Error, please try again." << endl;
		}
	}
}

void PlayListApp::printSongs(vector<Song> foundSongs)
{
	for (unsigned i = 0; i < foundSongs.size(); i++)
	{
		foundSongs[i].writeTo(cout);
		cout << endl;
	}
}
