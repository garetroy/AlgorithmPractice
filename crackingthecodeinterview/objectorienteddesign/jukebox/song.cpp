#include "song.h"

Song::Song(void)
{
    title      = "";
    length     = 0;
    albumPos   = 0;
    binaryData = (char*) new char[1024];

    fill(binaryData, binaryData+1024, 0);
}

Song::Song(string in)
{
    title      = in;
    length     = 0;
    albumPos   = 0;
    binaryData = (char*) new char[1024];

    fill(binaryData, binaryData+1024, 0);
}

Song::Song(string in, double _length)
{
    title      = in;
    length     = _length;
    albumPos   = 0;
    binaryData = (char*) new char[1024];

    fill(binaryData, binaryData+1024, 0);
}

Song::Song(string in, double _length, int pos)
{
    title      = in;
    length     = _length;
    albumPos   = pos;
    binaryData = (char*) new char[1024];
    
    fill(binaryData, binaryData+1024, 0);
}

Song::Song(string in, double _length, int pos, char* binarydata)
{
    title      = in;
    length     = _length;
    albumPos   = pos;
    binaryData = (char*) new char[1024];
    strcpy(binaryData, binarydata); 
}

Song::~Song(void)
{
    if(binaryData != NULL)
        delete[] binaryData;
}

void
Song::setLength(double _length)
{
    length = _length;
}

void
Song::setAlbumPos(int pos)
{
    albumPos = pos;
}

void
Song::setTitle(string in)
{
   title = in;
}

void
Song::setTitle(char* in)
{
   title = in;
} 

void
Song::setBinaryData(char* in)
{
    delete [] binaryData;
    
    binaryData = (char*) new char[1024];
    
    strcpy(binaryData, in);
} 

double
Song::getLength(void)
{
    return length;
}

string
Song::getTitle(void)
{       
    return title;
}

int
Song::getAlbumPos(void)
{
    return albumPos;
}

char*
Song::getBinaryData(void)
{
    return binaryData;
}

ostream & operator<<(ostream &os, const Song& in)
{
    return os << in.binaryData;
}
    
