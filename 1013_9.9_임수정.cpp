#include<iostream>
#include<cmath>
using namespace std;

class LinearEquation {
	int  a, b, c, d, e, f;
public:
	LinearEquation(int a, int b, int c, int d, int e, int f) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->e = e;
		this->f = f;
	}
	int getA() {
		return a;
	}
	int getB() {
		return b;
	}
	int getC() {
		return c;
	}
	int getD() {
		return d;
	}
	int getE() {
		return e;
	}
	int getF() {
		return f;
	}
	bool isSolvable() {
		if (a*d - b * c != 0)
			return true;
		else
			return false;
	}
	double getX() {
		return (e*d - b * f) / (a*d - b * c);
	}
	double getY() {
		return (a*f - e * c) / (a*d - b * c);
	}

};
int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	LinearEquation L1(a, b, c, d, e, f);
	if (!L1.isSolvable())
		cout << "The equation has no solution" << endl;
	else
		cout << "(" << L1.getX() << ", " << L1.getY() << ")" << endl;
	return 0;
}