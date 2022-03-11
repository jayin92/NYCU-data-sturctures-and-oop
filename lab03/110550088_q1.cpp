#include <cstdio>
#include <vector>
#include <iostream>
#include <string> 
using namespace std;
//TODO:Finish the class, you can add thing you need
class Student {
public:
    Student(){};
    Student(string _name, string _text): name(_name), text(_text){
        WriteBlackboard(_name, _text);
    }
      static string SeeBlackBoard(){
        return _BlackBoard;
    };
private:
    static string _BlackBoard;
    static void WriteBlackboard(string name, string text){
        _BlackBoard += name;
        _BlackBoard += ":";
        _BlackBoard += text;
        _BlackBoard += "\n";
    };
    string name;
    string text;
};

string Student::_BlackBoard = "";

int main() {  
      string name,text;
      vector<Student> Students;
      while(cin>>name>>text){
        Student new_ = Student(name, text);
        Students.push_back(new_);
    } 
      cout <<Students.size()<<endl<<Student::SeeBlackBoard();
    return 0;
}