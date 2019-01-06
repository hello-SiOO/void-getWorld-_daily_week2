#include<iostream>
#include<ctime>
using namespace std;

class Date {
	int year;
	int month;
	int day;
public:
	Date() {
		setDate(time(0));
	}
	Date(int newTime) {
		setDate(newTime);
	}
	Date(int newYear, int newMonth, int newDay) {
		year = newYear;
		month = newMonth;
		day = newDay;
	}
	int getYear() {
		return year;
	}
	int getMonth() {
		return month;
	}
	int getDay() {
		return day;
	}
	void setDate(int elapseTime) {
		int totaldate = elapseTime / 60 / 60 / 24;
		int i;
		year = 1970;
		for (i = 0; i < totaldate;) {
			if (!isLeapYear(year) && totaldate - i < 365 || isLeapYear(year) && totaldate - i < 366)
				break;
			if (isLeapYear(year))
				i += 366;
			else
				i += 365;
			year++;
		}
		month = 1;
		int leftdate = totaldate - i;
		int j;
		for (j = 0; j < leftdate;) {
			if (month == 4 || month == 6 || month == 9 || month == 11) {
				if (leftdate - j < 30)
					break;
			}
			else if (isLeapYear(year) && month == 2 && leftdate - j < 29 || !isLeapYear(year) && month == 2 && leftdate - j < 28)
				break;
			else {
				if (leftdate - j < 31)
					break;
			}

			if (isLeapYear(year) && month == 2)
				j += 29;
			else if (!isLeapYear(year) && month == 2)
				j += 28;
			else if (month == 4 || month == 6 || month == 9 || month == 11)
				j += 30;
			else j += 31;

			month++;
		}
		day = leftdate - j + 1;
	}
	bool isLeapYear(int year)
	{
		return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
	}
};
int main() {
	Date d1;
	cout << d1.getYear() << "년 " << d1.getMonth() << "월 " << d1.getDay() << "일" << endl;
	Date d2(561555550);
	cout << d2.getYear() << "년 " << d2.getMonth() << "월 " << d2.getDay() << "일" << endl;

	return 0;
}
