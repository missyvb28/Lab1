/* PlayList.h declares class PlayList.
 * Student Name: Melissa Van Baren
 * Date: 9/13/17
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include "Song.h"
#include <vector> //STL vector
#include <string>
using namespace std;

class PlayList {
public:
	PlayList(const string& fileName);
	unsigned getNumSongs() const;
	vector<Song> searchByArtist(const string& artist) const;
	vector<Song> searchByYear(int year) const;
	vector<Song> searchByTitlePhrase(const string& phrase);
	vector<Song> addSong(const Song& newSong);
	vector<Song> removeSong(const Song& aSong);
	void save() const;
private:
	vector<Song> mySongs;
	string myFileName;
};

#endif /* PLAYLIST_H_ */
