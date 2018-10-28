#include <iostream>
#include "song.h"

using namespace std;

   Song::Song(string title, string artist, int size) {

      this->title = title;
      this->artist = artist;
      this->size = size;

   }

   string Song::getTitle() {

      return title;

   }

   string Song::getArtist() {

      return artist;

   }

   int Song::getSize() {

      return size;

   }

   void Song::setTitle(string newTitle) {

      title = newTitle;

   }

   void Song::setArtist(string newArtist) {

      artist = newArtist;

   }

   void Song::setSize(int newSize) {

      size = newSize;

   }

   bool Song::operator ==(Song const &eq) {

      return (title == eq.title
              && artist == eq.artist
              && size == eq.size);   

   }

   bool Song::operator <(Song const &comp) {

      size_t length1 = (comp.artist).length();
      int artistLength = length1;
      
      for(int i = 0; i < artistLength; i++) {
         if(artist[i] < comp.artist[i]) {
            return true;
         }
      }

      size_t length2 = (comp.title).length();
      int titleLength = length2;

      for(int j = 0; j < titleLength; j++) {
         if(title[j] < comp.title[j]) {
            return true;
         }
      }

      if(size < comp.size) {
         return true;
      }
      else {
         return false;
      }

   }

   bool Song::operator >(Song const &comp) {
 
      size_t length1 = (comp.artist).length();
      int artistLength = length1;
      
      for(int i = 0; i < artistLength; i++) {
         if(artist[i] > comp.artist[i]) {
            return true;
         }
      }

      size_t length2 = (comp.title).length();
      int titleLength = length2;

      for(int j = 0; j < titleLength; j++) {
         if(title[j] > comp.title[j]) {
            return true;
         }
      }

      if(size > comp.size) {
         return true;
      }
      else {
         return false;
      }

   }

   Song::~Song() {
      //The destructor
   }

