#ifndef _SONG_H_
#define _SONG_H_

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Song{
    
    string title;
    double length;
    int    albumPos;
    char*  binaryData;

    public:
        
        Song(void);
        Song(string);
        Song(string,double);
        Song(string,double,int);
        Song(string,double,int,char*);
        ~Song(void);

        void   setLength(double);
        void   setAlbumPos(int);
        void   setTitle(string);
        void   setTitle(char*); 
        void   setBinaryData(char*);
        double getLength(void);
        string getTitle(void); 
        int    getAlbumPos(void);
        char*  getBinaryData(void);
 
        inline bool operator==(const Song& in) const;
        inline bool operator!=(const Song& in) const;
        
        friend ostream &operator<<(ostream &os, const Song& in); 
};

inline bool
Song::operator==(const Song& in) const
{ 
    return (in.length == this->length) && (in.title == this->title) && (in.albumPos == this->albumPos);    
}

inline bool
Song::operator!=(const Song& in) const
{
    return !((in.length == this->length) && (in.title == this->title) && (in.albumPos == this->albumPos));
}

#endif
