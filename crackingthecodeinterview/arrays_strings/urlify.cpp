#import <string>
#import <algorithm>
#import <iostream>

int 
main(int argc, char *argv[])
{
    if(argc == 1 || argc > 2){
        std::cerr << "This takes exactly one string" << std::endl;
        return -1;
    }
    
    std::string input = argv[1]; 
    for(int i = 0; i < input.length(); i++)
        if(input[i] == ' '){
            input.erase(i,1);
            input.insert(i,"%20");
        }

    std::cout << input << std::endl;
}
