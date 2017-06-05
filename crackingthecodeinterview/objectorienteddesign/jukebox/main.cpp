#include "album.h"

int
main()
{
    string dog("DOG");
    string frog("FROG");
    Song oursong = Song(dog);
    Song oursong2 = Song(dog, 1.3);
    Song oursong22 = Song(dog, 1.3);
    Song oursong3 = Song(frog, 1.3, 4);

    char in[1024] = {'a'};


    if(oursong2 == oursong22) 
        cout << "SAME" << endl;

    oursong.setBinaryData(in);
    cout << oursong << endl; 

    string title("WOWZA"); 
    string title2("KOWZA");
    string genre("classical");
    string genre2("rock");

    Album newalbum = Album(title,genre);
    Album newalbum2 = Album(title2,genre2);
    Album copy2     = Album(title,genre);
    
    newalbum.addSong(&oursong);
    newalbum.addSong(&oursong3); 
    newalbum.addSongAt(&oursong3,1);
    copy2.addSong(&oursong);
    copy2.addSong(&oursong3);
    
    if(copy2 == newalbum)
        cout << "Equal" << endl;

    cout << newalbum << endl;
    cout << *newalbum.getSongAt(0) << endl;
}
