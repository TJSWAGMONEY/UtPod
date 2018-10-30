//Add documentation here

#include <iostream>
#include "song.h"

using namespace std;

   //Default Constructor
   Song::Song() {
    
      artist = "";
      title = "";
      size = 0;
    
   }

   //Constructor for the Song class
   Song::Song(string artist, string title, int size) {

      this->artist = artist;
      this->title = title;
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
   int Song::getSize() const {

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
      //Converts the length of the artist's name to an int
      //Also selects the smaller artist name length so that it's not comparing nonexistent characters
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
         if(artist[i] < comp.artist[i]) {
            return true;
         }
         if(artist[i] > comp.artist[i]) {
            return false;
         }
      }

      //Determines if one artist name  is the same as the other but with additional characters
      //Only useful for very specific edge cases
      //For example, if one artist were asdf and the other were asdf1234
      if((comp.artist).length() > artist.length()) {
         return true;
      }
      else if(artist.length() > (comp.artist).length()) {
         return false;
      }

      //If the artist's name is less than the other, the following code is ignored 

      //Converts the length of the title to an int
      //Also selects the smaller title length so that it's not comparing nonexistent characters
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
         if(title[j] > comp.title[j]) {
            return false;
         }
      }
 
      //Determines if one title is the same as the other but with additional characters
      //Only useful for very specific edge cases
      //For example, if one title were abcd and the other were abcd1234
      if((comp.title).length() > title.length()) {
         return true;
      }
      else if(title.length() > (comp.title).length()) {
         return false;
      }

      //If the title is less than the other, the following code is ignored

      //Compares the sizes of the songs
      if(size < comp.size) {
         return true;
      }
      else {
         return false;//Only occurs if the artist, then title, then size
                      //is not "less than" the other's
      }

   }

   //This method overloads the ">" operator, which is useful for sorting in the UtPod
   bool Song::operator >(Song const &comp) {

      //Converts the length of the artist's name to an int
      //Also selects the smaller artist name length so that it's not comparing nonexistent characters 
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
         if(artist[i] < comp.artist[i]) {
            return false;
         }
      }

      //Determines if one artist name is the same as the other but with additional characters
      if((comp.artist).length() > artist.length()) {
         return false;
      }
      else if(artist.length() > (comp.artist).length()) {
         return true;
      }

      //If the artist's name is greater than the other, the following code is ignored
      
      //Converts the length of the title to an int
      //Also selects the smaller title length so that it's not comparing nonexistent characters 
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
         if(title[j] < comp.title[j]) {
            return false;
         }
      }

      //Determines if one title is the same as the other but with additional characters
      if((comp.title).length() > title.length()) {
         return false;
      }
      else if(title.length() > (comp.title).length()) {
         return true;
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

