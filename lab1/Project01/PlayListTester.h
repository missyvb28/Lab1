	/* PlayListTester.h tests the PlayList class.
    * Student Name: Melissa Van Baren (mlv49)
    * Date: 9/13/17
    * Begun by: Joel Adams, for CS 112 at Calvin College.
    */


#ifndef PLAYLISTTESTER_H_
#define PLAYLISTTESTER_H_

class PlayListTester {
public:
	void runTests();
	void testConstructors();
	void testSearchByArtist();
	void testSearchByYear();
	void testSearchByTitlePhrase();
	void testAddSong();
	void testSave();
};

#endif /* PLAYLISTTESTER_H_ */
