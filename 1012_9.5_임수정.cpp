#include<iostream>
#include<ctime>
using namespace std;

class Time {
	int hour;
	int minute;
	int second;
public:
	Time() {
		setTime(time(0));
	}
	Time(int newTime){	//책에는 인수를 따로 넣으라는 표시가 없는데 그러면 오버로딩이 돼서 의미없는 매개변수 하나 줬는데 이렇게 하면 될까요? ㅠ
		setTime(newTime);
	}
	Time(int newHour, int newMinute, int newSecond) {
		hour = newHour;
		minute = newMinute;
		second = newSecond;
	}
	int getHour() {
		return hour;
	}
	int getMinute() {
		return minute;
	}
	int getSecond() {
		return second;
	}
	void setTime(int elapseTime) {
		second = elapseTime % 60;
		minute = (elapseTime /60) % 60;
		hour = (elapseTime / 3600) % 24;
	}


};
int main() {
	Time t1;
	cout << t1.getHour() << ":" << t1.getMinute() << ":" << t1.getSecond() << endl;

	Time t2(555550);
	cout << t2.getHour() << ":" << t2.getMinute() << ":" << t2.getSecond() << endl;
	system("pause");
	return 0;
}
