//Add documentation here

#ifndef SONG_H
#define SONG_H
#include <string>

using namespace std;

//Song class declaration
class Song {

   private:

      string artist;//Contains the song's artist
      string title;//Contains the song's title
      int size;//Contains the size of the song in MB

   public:
      //Default Constructor
      Song();
   
      //Preconditions:
      //The title and artist cannot be blank
      //The size must be greater than zero
      Song(string artist, string title, int size);

      string getTitle();//Method that returns the title of the song
      string getArtist();//Method that returns the artist of the song
      int getSize() const;//Method that returns the size of the song

      void setTitle(string newTitle);//Method that changes the title of the song
      void setArtist(string newArtist);//Method that changes the artist of the song
      void setSize(int newSize);//Method that changes the size of the song

      bool operator ==(Song const &eq);//Overloads the "==" operator
      bool operator <(Song const &comp);//Overloads the "<" operator
      bool operator >(Song const &comp);//Overloads the ">" operator
      bool operator !=(Song const &eq);//Overloads the "!=" operator

      ~Song();//The deconstructor

};

#endif
