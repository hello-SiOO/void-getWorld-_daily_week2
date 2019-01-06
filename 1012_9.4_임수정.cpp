#include<iostream>
#include<cmath>
using namespace std;

class MyPoint{
	double x, y;
public:
	MyPoint(){
		x=0;
		y=0;
	}
	MyPoint(double x, double y){
		this->x = x ;
		this->y = y;
	}
	double getX(){
		return x;
	}
	double getY(){
		return y;
	}
	double getdistance(double nX, double nY){
		return sqrt(abs(x-nX)*abs(x-nX) + abs(y-nY)*abs(y-nY));
	}

};
int main (){
	MyPoint p1;
	MyPoint p2(10, 30.5);
	cout<<"(" << p1.getX() <<", "<<p1.getY() <<")" <<endl;
	cout<<"(" << p2.getX() <<", "<<p2.getY() <<")" <<endl;
	cout << p1.getdistance(p2.getX(),p2.getY())<<endl;

	return 0;
}
