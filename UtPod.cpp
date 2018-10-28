//
// Created by Lin on 10/24/2018.
//
#include <cstdlib>
#include <string.h>
#include <iostream>
#include "UtPod.h"
#include "song.h"

using namespace std;

int remainingMem;

//default constructor
UtPod::UtPod() {
    memSize = MAX_MEMORY;
    remainingMem = getTotalMemory();
}

//overloaded construction, takes user input for size
UtPod::UtPod(int size) {
    if (size > MAX_MEMORY || size <= 0)
        memSize = MAX_MEMORY;
    else
        memSize = size;
    remainingMem = getTotalMemory();
}

//method adds song into UTPod
int UtPod::addSong(const Song &s) {
    if (getRemainingMemory() >= s.getSize()) {
        //adding new song
        SongNode* newSong;
        newSong = new SongNode;
        newSong->s = s;
        newSong->next = songs;

        //updating head and UTPod remaining memory
        remainingMem -= s.getSize();
        songs = newSong;

        std::cout << "Song added successfully.\n";
        return SUCCESS;
    }

    std::cout << "Song add was unsuccessful. Not enough memory.\n";
    return NO_MEMORY;
}

//method removes song from UTPod
int UtPod::removeSong(const Song &s) {
    SongNode* previous = NULL;
    SongNode* current = songs;

    //LL traversal, locating target song
    for (; current != NULL && current->s != s; previous = current, current = current->next);

    //case song was not found
    if (current == NULL) {
        std::cout << "Song NOT found. Removal unsuccessful\n";
        return NOT_FOUND;
    }

    //case 1st song in LL is the target
    if (previous == NULL)
        songs = songs->next;
    else
        previous->next = current->next;

    remainingMem += s.getSize();
    delete current;
    std::cout << "Song found. Removal successful\n";
    return SUCCESS;
}

//method displays all songs in UTPod
void UtPod::showSongList() {
    //traverses LL
    SongNode* tempHead = songs;
    while (tempHead != NULL) {
        std::cout << tempHead->s.getTitle() << ", " << tempHead->s.getArtist() << ", " << tempHead->s.getSize() << " MB\n";
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
    remainingMem = getTotalMemory();
}

int UtPod::getRemainingMemory() {
    return remainingMem;
}

//method sorts UtPod in ascending order of song size
void UtPod::sortSongList() {
    SongNode* tempHead = songs;
    Song tempSong;
    int numSongs = 0;

    //finds number of songs in UtPod
    for(; tempHead != NULL; tempHead = tempHead->next, numSongs++);

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

/*    //bubble sort algorithm
    //SongNode* tempNode = NULL;
    for (int i = 0; i < numSongs; i++) {
        for (int j = 0; j < numSongs; j++) {
            if (tempHead->s > tempHead->next->s) {
                tempNode = tempHead;
                tempHead = tempHead->next;
                tempHead->next = tempNode;
            }
        }
    }*/

void UtPod::shuffle() {

}

UtPod::~UtPod() {
    //Destructor
}
