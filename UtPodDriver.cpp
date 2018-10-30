#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include "song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[]) {

    UtPod t;//Creates the UtPod and names it t

    srand(time(0));

    //Output giving instructions for user
    system("clear");
    cout << "Instructions for using the UtPod:" << endl << endl;
    cout << "adds         adds a song to the UtPod" << endl;
    cout << "rems         removes a song from the UtPod" << endl;
    cout << "shuf         shuffles the UtPod's song list" << endl;
    cout << "show         shows the UtPod's song list" << endl;
    cout << "sort         sorts the UtPod's song list" << endl;
    cout << "gett         gets the total memory of the UtPod" << endl;
    cout << "getr         gets the remaining memory of the UtPod" << endl;
    cout << "inst         reprints the commands" << endl;
    cout << "exit         exits the program" << endl << endl;

    string mainInput;
    int closeProgram = 0;
    while(closeProgram != 1) {

        cout << "What would you like to do? ";
        cin >> mainInput;
        cout << endl;

        if(mainInput == "adds") {
            string songArtist;
            string songTitle;
            string strSize;

            cin.clear();
            cin.sync();
            cout << "Artist: ";
            getline(cin, songArtist);

            cin.clear();
            cout << "Title: ";
            getline(cin, songTitle);

            cin.clear();
            cout << "Size: ";
            getline(cin, strSize);
            cout << endl;

            int songSize;
            istringstream(strSize) >> songSize;

            Song newSong(songArtist, songTitle, songSize);
            int addCheck = t.addSong(newSong);

            if(addCheck == 0)
                cout << "Song successfully added to UtPod." << endl;
            else if(addCheck == -1)
                cout << "There is not enough memory left in the UtPod to add the song." << endl;
            else
                cout << "Something went wrong with adding the song." << endl;
        }

        if(mainInput == "rems") {
            string remArtist;
            string remTitle;
            string strRemSize;

            cin.clear();
            cin.sync();
            cout << "Artist: ";
            getline(cin, remArtist);

            cin.clear();
            cout << "Title: ";
            getline(cin, remTitle);

            cin.clear();
            cout << "Size: ";
            getline(cin, strRemSize);
            cout << endl;

            int songRemSize;
            istringstream(strRemSize) >> songRemSize;

            Song removeSong(remArtist, remTitle, songRemSize);
            int removeCheck = t.removeSong(removeSong);

            if(removeCheck == 0)
                cout << "Song successfully removed from UtPod." << endl;
            else if(removeCheck == -2)
                cout << "Song removal unsuccessful. Song NOT found." << endl;
            else
                cout << "Something went wrong with removing the song." << endl;
        }

        if(mainInput == "shuf" || mainInput == "shuffle") {

            t.shuffle();
            cout << "Shuffled the songs in the UtPod." << endl;

        }

        if(mainInput == "show") {

            t.showSongList();

        }

        if(mainInput == "sort") {

            t.sortSongList();
            cout << "Sorted the songs in the UtPod in ascending order." << endl;

        }

        if(mainInput == "gett") {

            cout << "The total memory of the UtPod is " << t.getTotalMemory() << " MB." << endl;

        }

        if(mainInput == "getr") {

            cout << "There are " << t.getRemainingMemory() << " MB of memory remaining in the UtPod." << endl;

        }

        if(mainInput == "inst") {

            system("clear");
            cout << "Instructions for using the UtPod:" << endl << endl;
            cout << "adds         adds a song to the UtPod" << endl;
            cout << "rems         removes a song from the UtPod" << endl;
            cout << "shuf         shuffles the UtPod's song list" << endl;
            cout << "show         shows the UtPod's song list" << endl;
            cout << "sort         sorts the UtPod's song list" << endl;
            cout << "gett         gets the total memory of the UtPod" << endl;
            cout << "getr         gets the remaining memory of the UtPod" << endl;
            cout << "inst         reprints the commands" << endl;
            cout << "exit         exits the program" << endl << endl;

        }

        if(mainInput == "exit") {

            closeProgram = 1;

        }

        cout << endl;

    }
}
