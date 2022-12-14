#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
#include <vector>

using namespace std;

string alphabet = "abcdefghijklmnopqrstuvwxyz";
map<char,int> prioritymap;

int main()
{
    for (int i = 0; i < alphabet.length() *2; i++){
        if (i<26){
            char c = alphabet.at(i);
            prioritymap.insert(pair<char,int>(c, i+1));
        }
        else{
            char c = toupper(alphabet.at(i%26));
            prioritymap.insert(pair<char,int>(c, i+1));
        }
    }

    //used to print out the map
    // map<char, int>::iterator itr;
    // cout << "\nThe map prioritymap is : \n";
    // cout << "\tKEY\tELEMENT\n";
    // for (itr = prioritymap.begin(); itr != prioritymap.end(); ++itr) {
    //     cout << '\t' << itr->first << '\t' << itr->second
    //          << '\n';
    // }
    // cout << endl;

    ifstream myinput ("input.txt");
    string mystring;
    int sumofpriorities = 0;

    if(myinput.is_open()){
        while(myinput){
            getline(myinput,mystring);

            if(!mystring.empty()){
                string container1 = mystring.substr(0, mystring.length()/2);
                string container2 = mystring.substr(mystring.length()/2);
                
                //i heckin love hack solutions
                int flag = 0;
                for (int i = 0; i <container1.length(); i++){
                    if (flag == 1){
                        flag = 0;
                        break;
                    }
                    for (int j = 0; j < container2.length(); j++){
                        if(container1.at(i) == container2.at(j)){
                            char repeatedchar = container1.at(i);
                            int priority = prioritymap.at(repeatedchar);
                            sumofpriorities = sumofpriorities + priority;
                            flag = 1;
                            break;
                        }
                    }
                }
            
            }
        }
    }

    cout << "Sum of Priorities is: " << sumofpriorities << endl;
}
