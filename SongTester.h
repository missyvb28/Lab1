 /* SongTester.h declares a test-class for class Song.
    * Student Name: Melissa Van Baren (mlv49)
    * Date: 9/12/17
    * Begun by: Joel Adams, for CS 112 at Calvin College.
    */

//What methods/functions you can run on the songs to test them


#ifndef SONGTESTER_H_
#define SONGTESTER_H_

class SongTester {
public:
	void runTests();
	void testConstructors(); //make constructor a thing in the header so the program knows it can do stuff with it
	void testReadFrom();
	void testWriteTo();
};

#endif /* SONGTESTER_H_ */
