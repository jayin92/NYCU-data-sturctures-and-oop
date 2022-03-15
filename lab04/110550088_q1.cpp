#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Character
{
private:
	string Name;
    int Hp;
	int Sp;
	
public:
	void setName(string Name){ this->Name=Name; }
    void setHp(int Hp){ this->Hp=Hp; }
    void setSp(int Sp){ this->Sp=Sp; }
    
    void showStasus()
    {
    	cout << "Name:" << this->Name << endl;
        cout << "HP:" << this->Hp << endl;
        cout << "SP:" << this->Sp << endl;
    }
};

class Player : public Character
{
private:
	int ATK;
	int DEF;
	
public:

	Player(string Name,int Hp,int Sp){
		//TO DO
		setName(Name);
		setHp(Hp);
		setSp(Sp);
		ATK=15;
		DEF=10;
	}
	
    void showPlayerStasus()
    {
		showStasus();
		cout << "ATK:" << ATK << endl;
		cout << "DEF:" << DEF << endl;
    	//TO DO
    }
    
};

class Monster : public Character
{	
	private:
		int Exp;
	public:
		Monster(string Name, int Hp, int Sp, int Exp){
			setName(Name);
			setHp(Hp);
			setSp(Sp);
			this -> Exp = Exp;
		}
		void showMonsterStasus(){
			showStasus();
			cout << "EXP:" << Exp << endl;
		}
	//TO DO    
};

int main()
{
	string n1,n2;
	int a,b,c,d,e;
	cin >> n1 >> a >> b;
	cin >> n2 >> c >> d >> e;

	Player P1(n1,a,b);
	P1.showPlayerStasus();

	Monster M1(n2,c,d,e);
	M1.showMonsterStasus();

    return 0;
}