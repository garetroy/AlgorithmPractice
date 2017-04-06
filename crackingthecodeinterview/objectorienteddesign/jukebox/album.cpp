#include "album.h"

Album::Album(void)
{
    albumTitle = "";
    genre      = "";
}

Album::Album(string intitle, string ingenre)
{
    albumTitle = intitle;
    genre      = ingenre;
} 

void
Album::setAlbumTitle(string in)
{
    albumTitle = in;
}

void
Album::setGenre(string in)
{
    genre = in;
}

void
Album::addSong(Song& song)
{
    songs.push_back(song);
}   

void
Album::addSongAt(Song& song, int in)
{
    if(in >= songs.size()){
        cerr << "Cannot song at place " << in << " because albumsize is " << songs.size() << endl;
        return; 
    }

    songs.insert(songs.begin()+in, song);
}

string
Album::getAlbumTitle(void)
{
    return albumTitle;
}

string
Album::getGenre(void)
{
    return genre;
}

Song*
Album::getSongAt(int in)
{
    return &songs.at(in);
}

ostream & operator<<(ostream &os, Album& in)
{
    for( auto &i : in.songs)
        os << i.getTitle();
    
    return os;
}
