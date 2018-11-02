// UtPodDriver.cpp
//
// On our honor, this programming project is our own work and we have not
// provided this code to any other student.
//
// Troy Jackson and James Lin
//
// taj777 and jl62356
//
// Section 5 digit ID: 16240

#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include "song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[]) {

   srand(time(0));

   system("clear");

   UtPod t;
   cout << endl << "Created UtPod of default size 512 MB." << endl << endl;

   cout << "Testing getTotalMemory() and getRemainingMemory():" << endl;
   cout << "The total memory of the UtPod is " << t.getTotalMemory() << " MB." << endl;
   cout << "There are " << t.getRemainingMemory() << " MB of memory remaining." << endl;
   cout << "Since there are no songs in the UtPod, this makes sense." << endl << endl;

   Song song1("Queen","Bohemian Rhapsody",47);
   cout << "Created Song song1. Testing getArtist(), getTitle() and getSize():" << endl;
   cout << "song1's artist is " << song1.getArtist() << "." << endl;
   cout << "song1's title is " << song1.getTitle() << "." << endl;
   cout << "song1's size is " << song1.getSize() << " MB." << endl;
   int addCheck = t.addSong(song1);
   cout << "The result of adding song1 to the UtPod was " << addCheck << "." << endl;
   cout << "Testing showSongList():" << endl;
   t.showSongList();
   cout << endl;

   Song song2("Britney Spears","Toxic",100);
   Song song3("britney Spears","Toxic",100);
   Song song4("Britney Spears","toxic",100);
   addCheck = t.addSong(song2);
   cout << "Result of adding song2 ('" << song2.getArtist() << "' - '" << song2.getTitle() << "' - "
        << song2.getSize() << " MB): " << addCheck << "." << endl; 
   addCheck = t.addSong(song3);
   cout << "Result of adding song3 ('" << song3.getArtist() << "' - '" << song3.getTitle() << "' - "
        << song3.getSize() << " MB): " << addCheck << "." << endl; 
   addCheck = t.addSong(song4);
   cout << "Result of adding song4 ('" << song4.getArtist() << "' - '" << song4.getTitle() << "' - "
        << song4.getSize() << " MB): " << addCheck << "." << endl << endl; 
   cout << "Testing getTotalMemory() and getRemainingMemory():" << endl;
   cout << "The total memory of the UtPod is " << t.getTotalMemory() << " MB." << endl;
   cout << "There are " << t.getRemainingMemory() << " MB of memory remaining." << endl << endl;
 
   cout << "Testing showSongList():" << endl;
   t.showSongList();

   cout << endl  << "Testing sortSongList():" << endl;
   t.sortSongList();
   t.showSongList();

   cout << endl << "Testing shuffle():" << endl;
   t.shuffle();
   t.showSongList();

   Song song5("Nickelback","Photograph",200);
   addCheck = t.addSong(song5);
   cout << endl << "Result of adding song5 ('" << song5.getArtist() << "' - '" << song5.getTitle()
        << "' - " << song5.getSize() << " MB): " << addCheck << "." << endl; 
   cout << "This addition failed because there was not enough space."
        << endl << "song5 is " << song5.getSize()
        << " MB, but there are only " << t.getRemainingMemory() << " MB of space left in UtPod." << endl;
   
   int remCheck = t.removeSong(song4);
   cout << endl << "Result of removing song4: " << remCheck << "." << endl;
   cout << "There are now " << t.getRemainingMemory() << " MB of space left in UtPod." << endl;
   addCheck = t.addSong(song5);
   cout << "Result of adding song5: " << addCheck << "." << endl << endl;

   t.showSongList();

   cout << endl;
   return 0;

}
