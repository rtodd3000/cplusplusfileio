#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char *argv[]){
    ifstream og_file;
    ofstream out_file;
    string line;
    fstream fin;

    
    og_file.open("test.txt");
    // creates new file under command line name given by user
    out_file.open(argv[1]);

    // error handling to make sure our original test.txt file exists
    try{
        fin.open("test.txt", ios::in);
        if(!fin){
            throw string("file does not exist 1\n");
        }
    }
    catch(string err){
        cout << err;
    }
    // While loop that checks for case sensitivity
    while(getline(og_file,line)){
        char changedChar; // char variable that will output to new file
        for (char curChar : line){ // for every character on the line in the test.txt
            if (isupper(curChar)){ // checks if character is uppercase
                changedChar = tolower(curChar);
                out_file << changedChar; //outputs opposite case
                
            }
            else if (islower(curChar)){
                changedChar = toupper(curChar); // checks if character is lowercase
                out_file << changedChar; // outputs opposite case
            }
            else{
                out_file << curChar; //if not a letter, outputs char as is
            }
        }
    }
    out_file.close(); 
    return 0;
}
