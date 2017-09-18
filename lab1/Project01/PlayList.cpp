/* PlayList.cpp defines the class PlayList
 * Student Name: Melissa Van Baren
 * Date: 9/13/17
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "PlayList.h"
#include <fstream> //for the ifstream
#include <cassert> // for assert()
#include <string>
#include "Song.h"
using namespace std;

//Playlist Constructor
//Params: file name, a string
//Precondition: file name contains the name of the playlist file
PlayList::PlayList(const string& fileName)
{
	//open stream to the playlist file
	myFileName = fileName; //myfileName is a variable in the object, where ever mySongs goes, fileName goes along too; store "filename" in the object FileName
	ifstream fin(fileName.c_str() );
	assert(fin.is_open());

	//read and append songs to mySongs
	Song s;
	string separator;
	while (true)
	{
		s.readFrom(fin);
		if (!fin)
		{
			break;
		}
		getline(fin, separator);
		mySongs.push_back(s);  //appends song object to mySong variable, if vector full, makes vector bigger to fit
	}
	//close stream
	fin.close();
}

//Retrieve length of playlist
//Return the number of songs
unsigned PlayList::getNumSongs() const
{
	return mySongs.size(); //vector method .size tells how big
}

//Search via artist
//params: artist, a string
//returns a vector w all the songs by artists from playlist

vector<Song> PlayList::searchByArtist(const string& artist) const
{
	vector<Song> v;

	for (unsigned i = 0; i < mySongs.size(); i++)
	{
		if (mySongs[i].getArtist().find(artist) != string::npos)
			//mySongs[i] returns a song object, which is sent to getArtsit and turned into a string, which the find artist message returns either the position of 1st occurance of the artist in the list or that it's not found
		{
			v.push_back(mySongs[i]);
		}
	}
	return v;
}

//search by year
//params: year, a string
//returns a vector w all the songs by artists from playlist

vector<Song> PlayList::searchByYear(int year) const
{
	vector<Song> v;

	for (unsigned i = 0; i < mySongs.size(); i++)
	{
		int a = mySongs[i].getYear();
		string b = to_string(a);
		string theYear = to_string(year);
		//getYear is an int, can't use find(year) because that's a string method
		if (b.find(theYear) != string::npos)
		//mySongs[i] returns a song object, which the find year message returns either the position of 1st occurance of the year in the list or that it's not found
		{
			v.push_back(mySongs[i]);
		}
	}
		return v;
}

//search by title phrase
//params:  phrase, a string
//searches playlist for a string phrase and returns songs with phrase in the tilte

vector<Song> PlayList::searchByTitlePhrase(const string& phrase)
{
	vector<Song> v;
	//indexing can look for a sub string in a string and say how offset it is
	for (unsigned i = 0; i < mySongs.size(); i++)
	{
		if (mySongs[i].getTitle().find(phrase) < string::npos)
		{
			v.push_back(mySongs[i]);
		}
	}
	return v;
}

//add song to playlist
//params:  newSong, a variable of class Song
//returns vector of playlist + the new song

vector<Song> PlayList::addSong(const Song& newSong)
{
	mySongs.push_back(newSong); //append the new song to vector playlist
	return mySongs;
}

//remove song from playlist
//params:  aSong, a variable of class Song
//returns vector of playlist - the song you don't want

vector<Song> PlayList::removeSong(const Song& aSong)
{
	string phrase = aSong.getTitle(); //need to iterate through the list of songs until find the matching song, so erase is (index,index)
	//find the song you want to delete in the playlist
	for (unsigned i = 0; i < mySongs.size(); i++)
	{
		if (mySongs[i].getTitle().find(phrase, 0) < string::npos)
		{
			assert(mySongs[i].getArtist() == aSong.getArtist()); //check that looking at the correct song to delete
			assert(mySongs[i].getYear() == aSong.getYear());
			int index = i;
			mySongs.erase(mySongs.begin()+index);
			return mySongs;
		}
	}
	this->save();
	return mySongs;
}

//save the playlist to the file it originated from
//params:  n/a
//returns the saved playlist
void PlayList::save() const
{
	//cout << "Saving... " << endl;

	ofstream fout(myFileName.c_str() ); //output file
	assert(fout.is_open());

	//read and append songs to file

	for (unsigned i = 0; i < mySongs.size(); i++)
	{
		fout << mySongs[i].getTitle() << endl
		     << mySongs[i].getArtist() << endl
			 << mySongs[i].getYear() << endl
			 << endl;

	}
	fout.close();

	//cout << "Done!" << endl;
}
