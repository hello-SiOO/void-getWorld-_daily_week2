#include<iostream>
#include<iomanip>
using namespace std;

//�Լ�����
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
	//������ �Է�
	cout << "Enter full year(e.g.,2001): ";
	int year;
	cin >> year;
	
	//���� �Է�
	cout << "Enter month in number between 1 and 12: ";
	int month;
	cin >> month;
	
	//�ش� ������ �޿� ���� �޷� ���
	printMonth(year,month);
	
	return 0;
	 
 } 
 
 //�ش� ������ �޿� ���� �޷� ���
 void printMonth(int year, int month)
 {
 	//�޷��� ���� ���
	 printMonthTitle(year,month);
	 
	//�޷��� ���� ���
	printMonthBody(year, month); 
  } 
  //�� ���� ���
  void printMonthTitle(int year, int month)
  {
  	printMonthName(month);
  	cout << " "<< year<< endl ;
  	cout << "----------------------------" << endl;
  	cout << " Sun Mon Tue Wed Thu Fri Sat" << endl;
   } 
   
   //���� ���� �̸� ���ϱ�
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
	//���� ���� ���
	void printMonthBody(int year, int month)
	{
		//���� ù ��¥�� ���� ���� ���� ���ϱ�
		int startDay = getStartDay(year, month);
		
		//���� ��¥ �� ���ϱ�
		int numberOfDaysInMonth = getNumberOfDaysInMonth(year, month);
		
		//���� ù���� �� �տ� ���� �ֱ�
		int i = 0;
		for(i = 1; i < startDay; i++)
		{
			cout << setw(4) << i;

			if ((i + startDay) % 7 == 0 )
				cout << endl;
		}
	 } 

	// ���� ù ��¥�� ���� ���� ���� ���ϱ�
	int gatstartDay(int year, int month)
	{
		//1800�� 1�� 1�� ������ �� ��¥ �� ���ϱ�
		int startDay1800 = 3;
		int totalNumberOfDays = getTotalNumberOfDays(year, month);

		//���� ���� ��ȯ
		return (totalNumberOfDays + startDay1800) % 7;
	}

	//1800�� 1�� 1�� ������ �� ��¥ �� ���ϱ�
	int getTotalNumberOfDays(int year, int month)
	{
		int total = 0;

		//1800�⵵���� ���� -1������ �� ��¥ �� ���ϱ�
		for (int i = 1800; i< year; i++)
			if(isLeapYear(i))
				total = total + 366;
			else 
				total = total + 365;

		//1������ �޷��� �� �ٷ� ���ޱ����� ��¥ �� �߰��ϱ�
		for (int i = 1; i < month ; i++)
			total = total + getNumberOfDaysInMonth(year, i);

		return total;
	}

	// ���� �� �� ���ϱ�
	int getNumberOfDaysInMonth(int year, int month)
	{
		if(month ==1 || month == 3 || month == 5 || month == 7 ||
		   month == 8 || month == 10 || month == 12)
			return 31;

		if( month == 4 || month == 6 || month == 9 || month == 11)
			return 30;

		if (month == 2) return isLeapYear(year) ? 29 : 28;

		return 0; //���� ���� ���� ���
	}
	bool isLeapYear(int year)
	{
		return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
	}
