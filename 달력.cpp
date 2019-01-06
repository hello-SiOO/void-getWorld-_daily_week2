#include<iostream>
#include<iomanip>
using namespace std;

//함수원형
void printMonth(int year, int month);
void printMonthTitle(int year, int month);
void printMonthName(int month);
void printMonthBody(int year, int month);
int getStartDay(int year, int month);
int getTotalNumberOfDays(int year, int month);
int getNumberOfDaysInMonth(int year, int month);
bool isLeapYear(int year);

int main()
{
	//연도를 입력
	cout << "Enter full year(e.g.,2001): ";
	int year;
	cin >> year;
	
	//달을 입력
	cout << "Enter month in number between 1 and 12: ";
	int month;
	cin >> month;
	
	//해당 연도의 달에 대한 달력 출력
	printMonth(year,month);
	
	return 0;
	 
 } 
 
 //해당 연도의 달에 대한 달력 출력
 void printMonth(int year, int month)
 {
 	//달력의 제목 출력
	 printMonthTitle(year,month);
	 
	//달력의 내용 출력
	printMonthBody(year, month); 
  } 
  //달 제목 출력
  void printMonthTitle(int year, int month)
  {
  	printMonthName(month);
  	cout << " "<< year<< endl ;
  	cout << "----------------------------" << endl;
  	cout << " Sun Mon Tue Wed Thu Fri Sat" << endl;
   } 
   
   //달의 영어 이름 구하기
   void printMonthName(int month)
   {
   	switch(month)
   	{
   		case 1: 
   			cout << "January";
   			break;
   		case 2: 
   			cout << "February";
   			break;
		case 3: 
   			cout << "March";
   			break;
	    case 4: 
   			cout << "April";
   			break;
		case 5: 
   			cout << "May";
   			break;
		case 6: 
   			cout << "June";
   			break;	   	   	
	    case 7: 
   			cout << "July";
   			break;
   		case 8: 
   			cout << "August";
   			break;
		case 9: 
   			cout << "September";
   			break;
		case 10: 
   			cout << "October";
   			break;
		case 11: 
   			cout << "November";
   			break;
		case 12: 
   			cout << "December";  	   	
	   }
	} 
	//달의 내용 출력
	void printMonthBody(int year, int month)
	{
		//달의 첫 날짜에 대한 시작 요일 구하기
		int startDay = getStartDay(year, month);
		
		//달의 날짜 수 구하기
		int numberOfDaysInMonth = getNumberOfDaysInMonth(year, month);
		
		//달의 첫번쨰 날 앞에 공백 넣기
		int i = 0;
		for(i = 1; i < startDay; i++)
		{
			cout << setw(4) << i;

			if ((i + startDay) % 7 == 0 )
				cout << endl;
		}
	 } 

	// 달의 첫 날짜에 대한 시작 요일 구하기
	int gatstartDay(int year, int month)
	{
		//1800년 1월 1일 이후의 총 날짜 수 구하기
		int startDay1800 = 3;
		int totalNumberOfDays = getTotalNumberOfDays(year, month);

		//시작 요일 반환
		return (totalNumberOfDays + startDay1800) % 7;
	}

	//1800년 1월 1일 이후의 총 날짜 수 구하기
	int getTotalNumberOfDays(int year, int month)
	{
		int total = 0;

		//1800년도부터 연도 -1까지의 총 날짜 수 구하기
		for (int i = 1800; i< year; i++)
			if(isLeapYear(i))
				total = total + 366;
			else 
				total = total + 365;

		//1월부터 달력의 달 바로 전달까지의 날짜 수 추가하기
		for (int i = 1; i < month ; i++)
			total = total + getNumberOfDaysInMonth(year, i);

		return total;
	}

	// 달의 일 수 구하기
	int getNumberOfDaysInMonth(int year, int month)
	{
		if(month ==1 || month == 3 || month == 5 || month == 7 ||
		   month == 8 || month == 10 || month == 12)
			return 31;

		if( month == 4 || month == 6 || month == 9 || month == 11)
			return 30;

		if (month == 2) return isLeapYear(year) ? 29 : 28;

		return 0; //달이 맞지 않은 경우
	}
	bool isLeapYear(int year)
	{
		return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
	}
