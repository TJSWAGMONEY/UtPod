//DOCUMENT HERE

#ifndef SONG_H
#define SONG_H
#include <string>

using namespace std;

//Song class declaration
class Song {

   private:

      string title;
      string artist;
      int size;

   public:

      //Preconditions:
      //The title and artist cannot be blank
      //The size must be greater than zero
      Song(string title, string artist, int size);

      string getTitle();
      string getArtist();
      int getSize();

      void setTitle(string newTitle);
      void setArtist(string newArtist);
      void setSize(int newSize);

      bool operator ==(Song const &eq);
      bool operator <(Song const &comp);
      bool operator >(Song const &comp);
      bool operator !=(Song const &eq);

      ~Song();

};

#endif
