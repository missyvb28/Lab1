 /* SongTester.cpp defines the test-methods for class SongTester.
    * Student Name: Melissa Van Baren (mlv49)
    * Date: 9/12/17
    * Begun by: Joel Adams, for CS 112 at Calvin College.
    */

//what the methods/functions you're running to test songs actually do

#include "SongTester.h"
#include "Song.h"

#include <iostream>
#include <cassert>
#include <fstream>
#include <cstdlib>
using namespace std;

void SongTester::runTests()
{
	cout << "Testing class Song..." << endl;
	testConstructors();
	testReadFrom();
	cout << "All tests passed!" << endl;
}

// constructor initialization

void SongTester::testConstructors()
{
	//defualt constructor
	cout << " -constructors... " << flush;
	Song s; // empty variable s of type Song
	assert( s.getTitle() == "");
	assert( s.getArtist() == ""); //access values of instance variables
	assert( s.getYear() == 0);
	cout << "0 " << flush;

	//explicit constructor
	Song s1("Badge", "Cream", 1969); //1st song defined as s1 with title, artist, year variables defined
	assert(s1.getTitle() == "Badge");
	assert(s1.getArtist() == "Cream");
	assert(s1.getYear() == 1969);
	cout << " 1 " << flush;

	cout << "PASSED!" << endl;
}

//testing input method

void SongTester::testReadFrom()
{
	cout << "- readFrom()... " << flush;
	ifstream fin("testSongs.txt");
	assert(fin.is_open() );
	Song s;

	//read song 1
	s.readFrom(fin);
	assert(s.getTitle() == "Call Me Maybe");
	assert(s.getArtist() == "Carly Rae Jepsen");
	assert(s.getYear() == 2012);
	cout << " 0 " << flush;


	string seperator;
	getline(fin,seperator);

	//read song 2
	s.readFrom(fin);
	assert(s.getTitle() == "Let It Be");
	assert(s.getArtist() == "The Beatles");
	assert(s.getYear() == 1967);
	cout << " 1 " << flush;

	getline(fin,seperator);

	//read song 3
	s.readFrom(fin);
	assert(s.getTitle() == "Let It Be");
	assert(s.getArtist() == "Joan Baez");
	assert(s.getYear() == 1971);
	cout << " 2 " << flush;

	getline(fin,seperator);

	//read song 4
	s.readFrom(fin);
	assert(s.getTitle() == "Penny Lane");
	assert(s.getArtist() == "The Beatles");
	assert(s.getYear() == 1967);
	cout << " 3 " << flush;


	fin.close();
	cout << "PASSED!" << endl;
}

//testing writeTo() method
void SongTester::testWriteTo()
{
	cout << "- writeTo()... " << flush;

	//make 3 songs
	Song s1("Badge", "Cream", 1969);
	Song s2("Godzilla", "Blue Oyster Cult", 1977);
	Song s3("Behind Blue EYes", "The Wo", 1971);

	//write songs to output file
	ofstream fout("testSoungOutput.txt"); //creates .txt file
	assert(fout.is_open() );
	s1.writeTo(fout);
	s2.writeTo(fout);
	s3.writeTo(fout);
	fout.close(); //done adding stuff

	//use readFrom to see if writeTo is working
	ifstream fin("testSongOutput.txt");
	assert(fin.is_open() );
	Song s4, s5, s6;

	//read and check s4
	assert(s4.getTitle() == "Badge");
	assert(s4.getArtist() == "Cream");
	assert(s4.getYear() == 1969);
	cout << " 0 " << flush;

	//read and check s5
	assert(s5.getTitle() == "Godzilla");
	assert(s5.getArtist() == "Blue Oyster Cult");
	assert(s5.getYear() == 1977);
	cout << " 1 " << flush;

	//read and check s6
	assert(s6.getTitle() == "Behind Blue Eyes");
	assert(s6.getArtist() == "The Who");
	assert(s6.getYear() == 1971);
	cout << " 2 " << flush;

	fin.close();
	cout << " PASSED!" << endl;
}

