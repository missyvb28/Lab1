/* Song.cpp defines the methods for class Song (see Song.h).
 * Student Name: Melissa Van Baren (mlv49)
 * Date: 9/12/17
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "Song.h"

//make default constructor
Song::Song()
{
	myTitle = myArtist = ""; //both Title and Artist are empty strings
	myYear = 0;
}

//explicit constructor
/*Parameters:  Title (string), Artist (String), Year (unsigned int)
 * Postconditions: myTitle == Title &&
 * 				   myArtist == Artist &&
 * 				   myYear == Year.
 */

Song::Song(const string& title, const string& artist, unsigned year) //title, artist params flow into (but not out of) constructor, year is primitive type, so pass by values
{
	myTitle = title;
	myArtist = artist;
	myYear = year;
}

// getter method for myTitle (will return myTitle)
string Song::getTitle() const //will generate a "read only" version on title
{
	return myTitle;
}

//getter method for myArtist (will retrieve artist name from variable)
string Song::getArtist() const
{
	return myArtist;
}

//getter method for myYear (will retrieve when song published)
unsigned Song::getYear() const
{
	return myYear;
}


//Song input method
//Params:  in, and istream
//Preconditino: title, artist, year data already present
/* Post condition: the title, artist and year data have been read from in &&
 * 				  myTitle == title &&
 * 				  myArtist == artist &&
 * 				  myYear == year && */

void Song::readFrom(istream& in)
{
	getline(in, myTitle);
	getline(in, myArtist);
	string yearString;
	getline(in, yearString);
	myYear = atoi(yearString.c_str() ); //convert string version of year to unsigned int
}

//Song output method
//Params: out, an ostream
/*Post condition: out contains myTitle (new liine)
 * 							   myArtist (new line)
 * 							   mmyYear (new line) */

void Song::writeTo(ostream& out) const
{
	out << myTitle << '\n'
		<< myArtist << '\n'
		<< myYear << '\n';
}

//Song operator method
//param: song2, a Song
//Precondition: title, artist, year already present
//postcondition: compares song2 to song method is used on, returns true if match
bool Song::operator==(const Song& song2) const
{
	if (myTitle != song2.getTitle())
		return false;
	else if (myArtist != song2.getArtist())
		return false;
	else if (myYear != song2.getYear())
		return false;
	else
		return true;
}
