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
	Time(int newTime){	//å���� �μ��� ���� ������� ǥ�ð� ���µ� �׷��� �����ε��� �ż� �ǹ̾��� �Ű����� �ϳ� ��µ� �̷��� �ϸ� �ɱ��? ��
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
