#include <iostream>
#include <cmath>
using namespace std;
	class QuadraticEquation
	{
		int a, b, c;
		int D;
	public:
		QuadraticEquation(int Aa, int Bb, int Cc)//a,b,c를 인수로 갖는 생성자
		{
			a = Aa;
			b = Bb;
			c = Cc;
			D= b * b - 4 * a*c;
		}
		int getA()
		{
			return a;
		}
		int getB()
		{
			return b;
		}
		int getC()
		{
			return c;
		}
		int getDiscriminant()
		{
			return D;
		}
		double getRoot1()
		{
			return (-b + sqrt(D))/ (2 * a);
			
		}
		double getRoot2()
		{
			return (-b - sqrt(D)) / (2 * a);
		}
	};

	int main()
	{
		cout << "Enter the a,b,c: ";
		
		int a1, b2, c3;
		cin >> a1 >> b2 >> c3;
		QuadraticEquation ex1(a1, b2, c3);

		if (ex1.getDiscriminant() > 0)
		{
			cout << "The roots are "<< ex1.getRoot1()<<"and "<<ex1.getRoot2()<<endl;
		}
		else if (ex1.getDiscriminant() == 0)
		{
			cout << ex1.getRoot1();
		}
		else
		{
			cout << "THe equation has no real roots." << endl;
		}


		system("pause");
		return 0;
	}
