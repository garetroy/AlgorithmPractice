/*
    This program takes in a string and checks to see if the string only contains unique characters
*/
#import <string>
#import <iostream>

int
main(int argc, char *argv[])
{
    if(argc < 2 || argc > 3){
        std::cerr << "This program only takes one string" << std::endl; 
        return -1;
    }

    std::string input = argv[1];
    std::string newsr = "";

    for(int i = 0; i < input.length(); i++){
        if(newsr.find(input[i]) != std::string::npos){
            std::cerr << "The string does not include only unique characters" << std::endl;
            return 0;
        }
        newsr += input[i];
    }
    
    std::cerr << "This string only contains unique characters" << std::endl;
    return 0;
}
