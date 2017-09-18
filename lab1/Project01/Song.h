 /* Song.h declares a class for storing song information.
    * Student Name: Melissa Van Baren (mlv49)
    * Date: 9/12/17
    * Begun by: Joel Adams, for CS 112 at Calvin College.
    */

//the class "Song" is a thing, you can do this with it

#ifndef SONG_H_
#define SONG_H_

#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

//typedef int bool;
//#define true 1
//#define false 0

class Song
{
public: //what "normal" people can do with the playlist
	Song();
	Song(const string& title, const string& artist, unsigned year);
	string getTitle() const;
	string getArtist() const;
	unsigned getYear() const;
	void readFrom(istream& in);
	void writeTo(ostream& out) const;
	bool operator==(const Song& song2) const;

private: //"normal" people can't change this stuff; info on a song we want to keep track of
	string myTitle;
	string myArtist;
	unsigned myYear;
};

#endif /* SONG_H_ */
