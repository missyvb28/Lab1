/* main.cpp /tests the classes in our project.
    * Student Name: Melissa Van Baren (mlv49)
    * Date: 9/12/17
    * Begun by: Joel Adams, for CS 112 at Calvin College.
    * Purpose: Test Driven Developement experience via creating playlists
    */

#include "SongTester.h"
#include "PlayListTester.h"
#include "PlayListApp.h"

int main()
{
	SongTester sTester;
    sTester.runTests();
    PlayListTester plTester;
    plTester.runTests();
    PlayListApp Application;
    Application.menu();
}
