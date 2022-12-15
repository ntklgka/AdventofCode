#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int exercise1(string filename){
    string currLine = {};
    ifstream myinput(filename);
    int foundCounter = 0;

    if(myinput.is_open()){
        while(myinput){
            getline(myinput,currLine);

            if (!currLine.empty())
            {
                string firstElf = currLine.substr(0, currLine.find(','));
                string secondElf = currLine.substr(currLine.find(',') + 1, currLine.length());

                int firstElfStart = stoi(firstElf.substr(0, firstElf.find('-')));
                int firstElfEnd = stoi(firstElf.substr(firstElf.find('-') + 1, firstElf.length()));

                int secondElfStart = stoi(secondElf.substr(0, secondElf.find('-')));
                int secondElfEnd = stoi(secondElf.substr(secondElf.find('-') + 1, secondElf.length()));

                //check difference
                //the one with the smallest difference is contained on the one with the highest

                int firstElfDIfference = firstElfEnd - firstElfStart;
                int secondElfDifference = secondElfEnd - secondElfStart;

                if(firstElfDIfference >= secondElfDifference){
                    if(secondElfStart >= firstElfStart && secondElfEnd <= firstElfEnd){
                        foundCounter++;
                    }
                }
                else{
                    if(firstElfStart >= secondElfStart && firstElfEnd <= secondElfEnd){
                        foundCounter++;
                    }
                    
                }


            }
            
        }
    }

    return foundCounter;
}

int exercise2(string filename){
    string currLine = {};
    ifstream myinput(filename);
    int foundCounter = 0;
    int lineCounter = 0;
    int realCounter = 0;

    if(myinput.is_open()){
        while(myinput){
            getline(myinput,currLine);

            if(!currLine.empty()){
                lineCounter++;

                string firstElf = currLine.substr(0, currLine.find(','));
                string secondElf = currLine.substr(currLine.find(',') + 1, currLine.length());

                int firstElfStart = stoi(firstElf.substr(0, firstElf.find('-')));
                int firstElfEnd = stoi(firstElf.substr(firstElf.find('-') + 1, firstElf.length()));

                int secondElfStart = stoi(secondElf.substr(0, secondElf.find('-')));
                int secondElfEnd = stoi(secondElf.substr(secondElf.find('-') + 1, secondElf.length()));

                if(firstElfEnd < secondElfStart){
                    foundCounter++;
                }
                else if(secondElfEnd < firstElfStart){
                    foundCounter++;
                }
            }
            
        }
    }

    realCounter = lineCounter - foundCounter;

    return realCounter;
}

int main(){

  int foundCounter = exercise2("input.txt");

  cout << "The result is: " << foundCounter << endl;
}