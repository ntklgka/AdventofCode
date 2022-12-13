#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void exercise1(){
    ifstream myinput ("input.txt");
    string myline;
    vector<int> caloriessum;
    vector<int> currentcalories;

    if (myinput.is_open() ) { //if stream is open
        while(myinput){ //while file is good

            getline(myinput, myline); //get current line

            if(myline.empty()){
                int sum = accumulate(currentcalories.begin(),currentcalories.end(),0); //get the sum of all values in the array
                caloriessum.push_back(sum); //add the sum to the vector containing the sums
                currentcalories.clear();
            }
            else{
                int currline = stoi(myline);
                currentcalories.push_back(currline);
            }
        }
    }

    double max = *max_element(caloriessum.begin(),caloriessum.end());
    cout<<"Max value: "<< max <<endl;
}

void exercise2(){
    ifstream myinput ("input.txt");
    string myline;
    vector<int> caloriessum;
    vector<int> currentcalories;

    if (myinput.is_open() ) { //if stream is open
        while(myinput){ //while file is good

            getline(myinput, myline); //get current line

            if(myline.empty()){
                int sum = accumulate(currentcalories.begin(),currentcalories.end(),0); //get the sum of all values in the array
                caloriessum.push_back(sum); //add the sum to the vector containing the sums
                currentcalories.clear();
            }
            else{
                int currline = stoi(myline);
                currentcalories.push_back(currline);
            }
        }
    }
    int max1index = max_element(caloriessum.begin(),caloriessum.end()) - caloriessum.begin(); //get index of max value
    int max1 = *max_element(caloriessum.begin(),caloriessum.end()); //get max value
    caloriessum.erase(caloriessum.begin() + max1index); //remove max value from vector

    int max2index = max_element(caloriessum.begin(),caloriessum.end()) - caloriessum.begin();
    int max2 = *max_element(caloriessum.begin(),caloriessum.end());
    caloriessum.erase(caloriessum.begin() + max2index);

    int max3 = *max_element(caloriessum.begin(),caloriessum.end());

    cout<<"Max value: "<< max1 + max2 + max3 <<endl;
}
int main()
{
    exercise2();
}