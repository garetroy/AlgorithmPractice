#ifndef _ALBUM_H_
#define _ALBUM_H_

#include <vector>

#include "song.h"

class Album{
        
        string       albumTitle;
        string       genre;
        vector<Song> songs; 
        
        
    public:

        Album(void);
        Album(string);
        Album(string,string);

        void   setAlbumTitle(string);
        void   setGenre(string);
        void   addSong(Song&); 
        void   addSongAt(Song&,int);
        string getAlbumTitle(void);
        string getGenre(void);
        Song*  getSongAt(int);

        inline bool operator==(const Album&) const;
        inline bool operator!=(const Album&) const;

        friend ostream &operator<<(ostream&, Album&);
};

inline bool
Album::operator==(const Album& in) const
{
    bool eq = true;
    if(in.albumTitle != albumTitle && in.genre != genre && in.songs.size() != songs.size())
        return false;

    for(int i = 0; i < songs.size(); i++)
            if(in.songs.at(i) != songs.at(i))
                eq = false;

    return eq;
} 

inline bool
Album::operator!=(const Album& in) const
{
    bool neq = false;
    if(in.albumTitle != albumTitle && in.genre != genre && in.songs.size() != songs.size())
        return true;

    for(int i = 0; i < songs.size(); i++)
            if(in.songs.at(i) != songs.at(i))
                neq = true;
    return neq;
}

#endif
