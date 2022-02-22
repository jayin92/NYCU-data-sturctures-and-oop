

#include <iostream>
using namespace std;

class Calculator
{
    //TODO
    public:
        Calculator(int &num1, int &num2): _num1(num1), _num2(num2) {}
        void get_add_result(int &value);
        void get_sub_result(int &value);
        void get_mul_result(int &value);
        void get_div_result(int &value);
    private:
        int &_num1;
        int &_num2;

};

int main() {
    int num1 = 0;
    int num2 = 0;
    int value = 0;
  
    Calculator calc(num1, num2);
    while(cin >> num1 >> num2)
    {
        calc.get_add_result(value);
        cout << value << " ";
        calc.get_sub_result(value);
        cout << value << " ";
        calc.get_mul_result(value);
        cout << value << " ";
        calc.get_div_result(value);
        cout << value << endl;
    }

    return 0;
}

void Calculator::get_add_result(int &value){
    value = _num1 + _num2;
}


void Calculator::get_sub_result(int &value){
    value = _num1 - _num2;
}

void Calculator::get_mul_result(int &value){
    value = _num1 * _num2;
}

void Calculator::get_div_result(int &value){
    value = _num1 / _num2;
}

