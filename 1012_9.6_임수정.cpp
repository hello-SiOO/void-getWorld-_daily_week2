#include <iostream>
#include <cmath>
using namespace std;

class QuadraticEquation{
public:	
	int a;
	int b;
	int c;
	QuadraticEquation(int a, int b, int c){
		this -> a = a;
		this -> b = b;
		this -> c = c;
		
	}		
	int getA(){
		return a;
	}
	int getB(){
		return b;
	}
	int getC(){
		return c;
	}
	int getDiscriminant(){
		return b*b - 4*a*c;
	}
	double getRoot1(){
		return (-b + sqrt(b*b -4*a*c))/2*a;
	}
	double getRoot2(){
		return (-b -sqrt(b*b -4*a*c))/2*a;
	}	
};
int main(){
	QuadraticEquation q1(0,0,0);
	cin >> q1.a >> q1.b >>q1.c;
	if(q1.getDiscriminant()>0)
		cout << q1.getRoot1() << ", " << q1.getRoot2() << endl;
	else if(q1.getDiscriminant()==0)
		cout << q1.getRoot1();
	else
		cout << "The equation has no real roots" << endl;	
	
	return 0;
}
