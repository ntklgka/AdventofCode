#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int getValuefromLetter(char s){
    if (s == 'A' || s == 'X'){
        return 1;
    }
    else if (s == 'B' || s == 'Y'){
        return 2;
    }
    else if(s == 'C' || s == 'Z'){
        return 3;
    }

    return 0;
}

int getValuefromLine(string s){
    vector<vector<int>> myplaymatrix
    {
        {3,1,2}, //if opp plays rock
        {1,2,3}, //if opp plays paper
        {2,3,1} //if opp plays scissor
    };

    int opplay = getValuefromLetter(s.at(0));
    int resultneeded = getValuefromLetter(s.at(2));

    return myplaymatrix.at(opplay-1)[resultneeded-1];
    
}

void exercise1(){

    /*
    A - Rock (1)
    B - Paper (2)
    C - Scissors (3)
    */
    vector<vector<int>> resultmatrix
    {
        {3,6,0},
        {0,3,6},
        {6,0,3}
    };

    string mystring;

    ifstream myinput ("input.txt");

    int finalresult = 0;

    if(myinput.is_open()){
        while(myinput){
            getline(myinput,mystring);

            if (!mystring.empty()){
                char opponentchar = mystring.at(0);
                char mechar = mystring.at(2);

                int opponent = getValuefromLetter(opponentchar);
                int me = getValuefromLetter(mechar);

                finalresult = finalresult + me + resultmatrix.at(opponent-1)[me-1];
                
            }

        }
    }

    cout<<"Final result is: "<< finalresult <<endl;
}

void exercise2(){
    /*
    A - Rock (1)
    B - Paper (2)
    C - Scissors (3)
    */
    vector<vector<int>> resultmatrix
    {
        {3,6,0},
        {0,3,6},
        {6,0,3}
    };

    string mystring;

    ifstream myinput ("input.txt");

    int finalresult = 0;

    if(myinput.is_open()){
        while(myinput){
            getline(myinput, mystring);

            if(!mystring.empty()){
                char opponentchar = mystring.at(0);
                int opponent = getValuefromLetter(opponentchar);

                int me = getValuefromLine(mystring);

                finalresult = finalresult + me + resultmatrix.at(opponent-1)[me-1];
            }
        }
    }

    cout<< "Final Result is: "<< finalresult <<endl;
}

int main(){
    exercise2();
}