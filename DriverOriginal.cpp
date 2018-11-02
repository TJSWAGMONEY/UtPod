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

    string strPodSize;

    //asks user to set the memory size of UtPod
    cout << "UtPod Size: ";
    getline(cin, strPodSize);
    cout << endl;

    int sizeOfUtPod;
    istringstream(strPodSize) >> sizeOfUtPod;

    UtPod t(sizeOfUtPod); //Creates the UtPod and names it t

    //Output giving instructions for user
    system("clear");
    cout << "Instructions for using the UtPod:" << endl << endl;
    cout << "sets         sets memory of UtPod" << endl;
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
        getline(cin, mainInput);
        cout << endl;

        if(mainInput == "adds" || mainInput == "add" || mainInput == "addSong") {
            string songArtist;
            string songTitle;
            string strSize;

            cout << "Artist: ";
            getline(cin, songArtist);

            cout << "Title: ";
            getline(cin, songTitle);

            cout << "Size: ";
            getline(cin, strSize);
            cout << endl;

            int songSize;
            istringstream(strSize) >> songSize;

            if(songSize < 1) {
                cout << "That is not a valid song size." << endl;
            }
            else if(songArtist == "") {
                cout << "That is not a valid artist name." << endl;
            }
            else if(songTitle == "") {
                cout << "That is not a valid song title." << endl;
            }
            else {

                Song newSong(songArtist, songTitle, songSize);
                int addCheck = t.addSong(newSong);

                if(addCheck == 0)
                    cout << "Song successfully added to UtPod." << endl;
                else if(addCheck == -1)
                    cout << "There is not enough memory left in the UtPod to add the song." << endl;
                else
                    cout << "Something went wrong with adding the song." << endl;

            }

        }

        else if(mainInput == "rems" || mainInput == "rem" || mainInput == "removeSong") {
            string remArtist;
            string remTitle;
            string strRemSize;

            cout << "Artist: ";
            getline(cin, remArtist);

            cout << "Title: ";
            getline(cin, remTitle);

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

        else if(mainInput == "shuf" || mainInput == "shuffle") {

            t.shuffle();
            cout << "Shuffled the songs in the UtPod." << endl;

        }

        else if(mainInput == "show" || mainInput == "showSongList") {

            t.showSongList();

        }

        else if(mainInput == "sort" || mainInput == "sortSongList") {

            t.sortSongList();
            cout << "Sorted the songs in the UtPod in ascending order." << endl;

        }

        else if(mainInput == "gett" || mainInput == "getTotalMemory") {

            cout << "The total memory of the UtPod is " << t.getTotalMemory() << " MB." << endl;

        }

        else if(mainInput == "getr" || mainInput == "getRemainingMemory") {

            cout << "There are " << t.getRemainingMemory() << " MB of memory remaining in the UtPod." << endl;

        }

        else if(mainInput == "inst" || mainInput == "i" || mainInput == "instructions") {

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

        else if(mainInput == "exit" || mainInput == "e" || mainInput == "quit" || mainInput == "q") {

            closeProgram = 1;

        }

        else {

            cout << "Not a valid command." << endl;

        }

        cout << endl;

    }
}
