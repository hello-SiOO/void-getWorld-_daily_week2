#include<iostream>
#include<ctime>
using namespace std;
class Time{
	int hour, minute, second;
	public: 
	Time()//인수없는 생성자
	{
		setTime(time(0)); 
	 } 
	 Time(int time){
	 	setTime(time);
	 }
	 Time(int HOUR, int MINUTE, int SECOND){
	 	hour = HOUR;
	 	minute = MINUTE;
	 	second = SECOND;
	 }
	 int getHour(){
	 	return hour;
	 }
	 int getMinute(){
	 	return minute;
	 }
	 int getSecond(){
	 	return second;
	 }
	 void setTime(int elapseTime){
	 	second = elapseTime % 60;
	 	int totalMinutes = elapseTime/60;
	 	minute = totalMinutes%60;
	 	int totalHours = totalMinutes/60;
	 	hour = totalHours%24;
	 }
};
int main(){
	Time ex1;
	Time ex2(555550);
	cout << ex1.getHour() << " " << ex1.getMinute() << " " << ex1.getSecond() << endl;
	cout << ex2.getHour() << " " << ex2.getMinute() << " " << ex2.getSecond() << endl;
	return 0;
}
