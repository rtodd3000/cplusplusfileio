#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream file1;
ofstream file2;
string line;
fstream fin;
int userChoice; // variable to track the choice # the user chooses

// function to capitalize all the characters in the string
void cap(string line){
    char changedChar;
    for (char curChar : line){ // for every character on the line in the test.txt
        if (islower(curChar)){ // checks if character is uppercase
            changedChar = toupper(curChar);
            file2 << changedChar; //outputs opposite case
            
        }
        else{
            file2 << curChar; //if not a letter, outputs char as is
        }
    }
}

// function to lowercase all the characters in the string
void lower(string line){
    char changedChar;
    for (char curChar : line){ // for every character on the line in the test.txt
        if (isupper(curChar)){ // checks if character is uppercase
            changedChar = tolower(curChar);
            file2 << changedChar; //outputs opposite case
            
        }
        else{
            file2 << curChar; //if not a letter, outputs char as is
        }
    }
}

// function to remove all the numbers and punctuation in the string
void remove(string line){
    char changedChar;
    for (char curChar : line){ // for every character on the line in the test.txt
        if (!(curChar == '!' || curChar == '.' || curChar == '?' || isdigit(curChar))){ // checks if character is uppercase
            file2 << curChar; //outputs opposite case
        }
    }
}

// function to print the menu of choices to user
void menu(){
    cout << "Option 1: Capitilize the entire line" << endl;
    cout << "Option 2: Lowercase the entire line" << endl;
    cout << "Option 3: Remove all punctuation/numbers from the entire line" << endl;
} 


int main(){
    file1.open("input.txt");
    file2.open("output.txt");
    
    // error handling to make sure original file exists
    try{
        fin.open("input.txt", ios::in);
        if(!fin){
            throw string("file does not exist\n");
        }
    }

    catch(string err){
        cout << err;
    }

    // while loop that loops through each line in original file
    while(getline(file1,line)){
        //from here down, each line is modified based on user's choice from menu
        cout << "Pick a number from the menu: " << endl;
        menu();
        cin >> userChoice;
        if (userChoice == 1){
            cap(line);
            file2 << endl;
        }
        else if (userChoice == 2){
            lower(line);
            file2 << endl;
        }
        else if (userChoice == 3){
            remove(line);
            file2 << endl;
        }
    }
    // closing files
    file1.close();
    file2.close();
    return 0;
}