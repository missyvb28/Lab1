/* PlayListApp.h declares the class PlayListApp
 * Student Name: Melissa Van Baren
 * Date: 9/13/17
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#ifndef PLAYLISTAPP_H_
#define PLAYLISTAPP_H_

#include "Song.h"
#include <vector> //STL vector
#include <string>
using namespace std;

class PlayListApp {
public:
	PlayListApp();
	void menu() const;
	void printSongs(vector<Song> foundSong);
//	vector<Song> returnMenu(unsigned int menu);
};

#endif /* PLAYLISTAPP_H_ */
