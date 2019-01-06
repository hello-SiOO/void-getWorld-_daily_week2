#include<iostream>
using namespace std;

class EvenNumber{
	int value;
public:
	EvenNumber(){
		value = 0;
	}	
	EvenNumber(int value){
		this -> value = value;
	}
	int getValue(){
		return value;
	}
	int getNext(int currentValue){
		return currentValue+2;
	}
	int getPrevious(int currentValue){
		return currentValue-2;
	}
	void setValue(int newValue){
		value = newValue;
	}
};

int main(){
	EvenNumber e1(16);
	cout << "The next even number of "<< e1.getValue() << " is " << e1.getNext(e1.getValue()) << endl;
	cout << "The previous even number of "<< e1.getValue() << " is " << e1.getPrevious(e1.getValue()) << endl;	
	return 0;
}
