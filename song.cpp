#include <iostream>
#include "song.h"

using namespace std;

   //Constructor for the Song class
   Song::Song(string title, string artist, int size) {

      this->title = title;
      this->artist = artist;
      this->size = size;

   }

   //This method returns the title of the song
   string Song::getTitle() {

      return title;

   }

   //This method returns the artist of the song
   string Song::getArtist() {

      return artist;

   }

   //This method returns the size of the song
   int Song::getSize() {

      return size;

   }

   //This method sets the title of the song to a new value
   void Song::setTitle(string newTitle) {

      title = newTitle;

   }

   //This method sets the artist of the song to a new value
   void Song::setArtist(string newArtist) {

      artist = newArtist;

   }

   //This method sets the size of the song to a new value
   void Song::setSize(int newSize) {

      size = newSize;

   }

   //This method overloads the "==" operator, which is useful for various functions of the UtPod
   bool Song::operator ==(Song const &eq) {

      //Compares the title, artist, and size of the two songs to see if they are the same
      return (title == eq.title
              && artist == eq.artist
              && size == eq.size);   

   }

   //This method overloads the "!=" operator
   bool Song::operator !=(Song const &eq) {

      //Compares the title, artist, and size of the two songs to see if they are the same
      return (title != eq.title
              || artist != eq.artist
              || size != eq.size);   

   }

   //This method overloads the "<" operator, which is useful for sorting in the UtPod
   bool Song::operator <(Song const &comp) {
      cout << "in less than" << endl;
      //Converts the length of the artist's name to an int
      size_t length1a = (comp.artist).length();
      size_t length1b = artist.length();
      int artistLength;
      if(length1a < length1b) {
         artistLength = length1a;
      }
      else {
         artistLength = length1b;
      }
      cout << "length is: " << artistLength << endl;
      //Goes character by character through the artist names and compares      
      for(int i = 0; i < artistLength; i++) {
         cout << "in for loop, wtf" << endl;
         cout << "artist[i] is " << artist[i] << ", comp.artist[i] is " << comp.artist[i] << endl; 
         if(artist[i] < comp.artist[i]) {
            return true;
         }
      }

      //If the artist's name is less than the other, the following code is ignored 

      //Converts the length of the title to an int
      size_t length2a = (comp.title).length();
      size_t length2b = title.length();
      int titleLength;
      if(length2a < length2b) {
         titleLength = length2a;
      }
      else {
         titleLength = length2b;
      }

      //Goes through character by character and compares the titles
      for(int j = 0; j < titleLength; j++) {
         if(title[j] < comp.title[j]) {
            return true;
         }
      }

      //If the title is less than the other, the following code is ignored

      //Compares the sizes of the songs
      if(size < comp.size) {
         return true;
      }
      else {
         cout << "return false wtf wtf wtf" << endl;
         return false;//Only occurs if the artist, then title, then size
                      //is not "less than" the other's
      }

   }

   //This method overloads the ">" operator, which is useful for sorting in the UtPod
   bool Song::operator >(Song const &comp) {

      //Converts the length of the artist's name to an int
      size_t length1a = (comp.artist).length();
      size_t length1b = artist.length();
      int artistLength;
      if(length1a < length1b) {
         artistLength = length1a;
      }
      else {
         artistLength = length1b;
      }

      //Goes character by character through the artist names and compares      
      for(int i = 0; i < artistLength; i++) {
         if(artist[i] > comp.artist[i]) {
            return true;
         }
      }

      //If the artist's name is greater than the other, the following code is ignored
      
      //Converts the length of the title to an int
      size_t length2a = (comp.title).length();
      size_t length2b = title.length();
      int titleLength;
      if(length2a < length2b) {
         titleLength = length2a;
      }
      else {
         titleLength = length2b;
      }

      //Goes character by character through the song titles and compares
      for(int j = 0; j < titleLength; j++) {
         if(title[j] > comp.title[j]) {
            return true;
         }
      }

      //If the title is greater than the other, the following code is ignored

      //Compares the size of the two songs
      if(size > comp.size) {
         return true;
      }
      else {
         return false;//Only occurs if the artist, then title, then size
                      //is not "greater than" the other's
      }

   }

   //This is the destructor
   Song::~Song() {}

