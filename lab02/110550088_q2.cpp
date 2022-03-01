#include <iostream>
using namespace std;
 
class calculator
{
    private:
        int &a, &b, &c;
        int d = 0;
	public: 
      calculator(int &a): a(a), b(d), c(d) {}
      calculator(int &a, int &b): a(a), b(b), c(d) {}
      calculator(int &a, int &b, int &c): a(a), b(b), c(c) {}

      int add() {
          return a + b + c;
      }
};
 
int main()
{
    int a, b, c, d, e, f;
  
  	calculator c1(a);
    calculator c2(b, c);
    calculator c3(d, e, f);
  
  	cin >> a >> b >> c >> d >> e >> f ; 
    cout << c1.add() * c2.add() - c3.add() << endl;
    return 0;
}