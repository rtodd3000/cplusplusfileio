#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <ctype.h>
using namespace std;
int main(){
    ifstream og_file;
    string line;
    og_file.open("test.txt");
    while(getline(og_file,line)){
        for (char curChar : line){
            if (isupper(curChar)){
                putchar (tolower(curChar));
            }
            else if (islower(curChar)){
                putchar (toupper(curChar));
            }
            // else{
            //     cout << curChar << end;
            // }
        }
    }
    cout << line << endl;
    og_file.close();
    return 0;
}
