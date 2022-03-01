#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student {
public:
	Student( ) { }
	string generate_address(){
    	string res = "1001 University Road, Hsinchu, Taiwan 300, ROC, dorm ";
        res += dormitory;
        res += ", (";
        res += ID;
        res += ") ";
        res += first_name;
        res += " ";
        res += last_name;
        return res;
    }
    void modify(string first_name, string last_name, string dorm, string ID){
        this -> first_name = first_name;
        this -> last_name = last_name;
        this -> dormitory = dorm;
        this -> ID = ID;
    }
  	//Please implement the remain class
private:
	string first_name;
    string last_name;
	string dormitory;
	string ID;
};


int main() {
  	Student mStudent;
    /* Enter your code here. Read input from STDIN */
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    mStudent.modify(a, b, c, d);
  	cout << mStudent.generate_address() << endl;
    return 0;
}
