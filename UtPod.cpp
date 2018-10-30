#include <cstdlib>
#include <string.h>
#include <iostream>
#include "UtPod.h"
#include "song.h"

using namespace std;



//default constructor
UtPod::UtPod() {
    memSize = MAX_MEMORY;
    songs = NULL;
}

//overloaded construction, takes user input for size
UtPod::UtPod(int size) {
    if (size > MAX_MEMORY || size <= 0)
        memSize = MAX_MEMORY;
    else
        this->memSize = size;

    songs = NULL;
}

//method adds song into UTPod
int UtPod::addSong(const Song &s) {
    //checks if there is enough space in UtPod to add the requested song
    if (getRemainingMemory() >= s.getSize()) {
        //adding new song
        SongNode* newSong = new SongNode;
        newSong->s = s;
        newSong->next = songs;

        //updating head
        songs = newSong;

        return SUCCESS;
    }

    return NO_MEMORY;
}

//method removes song from UTPod
int UtPod::removeSong(const Song &s) {
    SongNode* previous = NULL;
    SongNode* current = songs;

    //LL traversal, locating target song
    for (; current != NULL && current->s != s; previous = current, current = current->next);

    //case song was not found
    if (current == NULL)
        return NOT_FOUND;

    //case 1st song in LL is the target
    if (previous == NULL)
        songs = songs->next;
    else
        previous->next = current->next;

    delete current;

    return SUCCESS;
}

//method displays all songs in UTPod
void UtPod::showSongList() {
    //traverses LL
    SongNode* tempHead = songs;
    while (tempHead != NULL) {
        std::cout << tempHead->s.getArtist() << ", " << tempHead->s.getTitle() << ", " << tempHead->s.getSize() << " MB\n";
        tempHead = tempHead->next;
    }
}

//method clears all songs from UTPod memory
void UtPod::clearMemory() {
    SongNode* temp;
    while (songs != NULL) {
        temp = songs;
        songs = songs->next;
        delete temp;
    }
}

//method calculates total memory used in UtPod
int UtPod::getMemoryUsed() {
    int totalMemUsed = 0;
    SongNode* tempHead = songs;

    //traverse LL accumulating the amount of memory used in UtPod
    while (tempHead != NULL) {
        totalMemUsed += tempHead->s.getSize();
        tempHead = tempHead->next;
    }
    return totalMemUsed;
}

//method finds the number of songs in UtPod
int UtPod::getNumSongs() {
    SongNode* tempHead = songs;
    int numSongs = 0;

    //finds number of songs in UtPod
    for(; tempHead != NULL; tempHead = tempHead->next, numSongs++);

    return numSongs;
}

int UtPod::getRemainingMemory() {
    int totalMemUsed = getMemoryUsed();
    int totalMem = getTotalMemory();
    return (totalMem - totalMemUsed);
}

//method sorts UtPod in ascending order of song size
void UtPod::sortSongList() {
    SongNode* tempHead = songs;
    Song tempSong("", "", 0);
    int numSongs = getNumSongs();

    //bubble sort algorithm
    for (int i = 0; i < numSongs; i++) {
        //iterates through list until next is NULL
        while (tempHead->next != NULL) {
            if (tempHead->s > tempHead->next->s) {
                tempSong = tempHead->s;
                tempHead->s = tempHead->next->s;
                tempHead->next->s = tempSong;
            }
            //increment the node
            tempHead = tempHead->next;
        }
        //resets tempHead
        tempHead = songs;
    }
}

//swaps head with randomly found node in LL
void UtPod::swap(SongNode* swapNode) {
    Song tempSong = songs->s;
    songs->s = swapNode->s;
    swapNode->s = tempSong;
}

//shuffles LL 10*n number of time, where n is the number of songs
void UtPod::shuffle() {
    int numSongs = getNumSongs();
    int idx;
    SongNode* swapNode;

    //swaps 10*n times
    for (int i = 0; i < 10*numSongs; i++) {
        idx = rand() % numSongs;
        swapNode = songs;

        //traverses LL, locates swap node
        for (int j = 0; j < idx; j++)
            swapNode = swapNode->next;

        swap(swapNode);
    }
}

UtPod::~UtPod() {
    //The destructor
}
