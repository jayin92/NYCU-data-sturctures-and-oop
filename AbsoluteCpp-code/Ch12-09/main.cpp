//
//  main.cpp
//  AbsoluteCpp_ch12_9
//
//  Demonstration of the stringstream class. This program takes a string with a name followed by scores. It uses a stringstream to extract the name as a string, the scores as integers, then calculates the average score. The name and average are placed into a new string.

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    stringstream ss;
    string scores = "Luigi 70 100 90";
    
    // Clear the stringstream
    ss.str("");
    ss.clear();
    
    //Put the scores into the stringstream
    ss << scores;    
    
    // Extract the name and average the scores
    string name = "";
    int total = 0, count = 0, average = 0;
    int score;
    ss >> name; //Read the name
    while (ss >> score) // Read until the end of the string
    {
        count++;
        total += score;
    }
    if (count > 0)
    {
        average = total / count;
    }
    
    // Clear the stringstream
    ss.clear();
    ss.str("");
    
    // Put the name and average into the stringstream
    ss << "Name: " << name << " Average: " << average;
    // Output as a string
    cout << ss.str() << endl;
    
    return 0;
}
