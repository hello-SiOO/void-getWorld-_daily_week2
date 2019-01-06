#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
const int ARRAY_SIZE = 100000;
int list[ARRAY_SIZE];
class StopWatch {
	long long startTime;
	long long endTime;
public:
	StopWatch() {
		startTime = time(0);
	}
	long long getStartTime() {
		return startTime;
	}
	long long getEndTime() {
		return endTime;
	}
	void start() {
		startTime = time(0);
	}
	void stop() {
		endTime = time(0);
	}
	int getElapsedTime() {
		return (endTime - startTime);
	}
};

void selectionSort(int array[]) {
	for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
		int current_max = array[i];
		int current_maxIndex = i;
		for (int j = i - 1; j >= 0; j--) {
			if (current_max < array[j]) {
				current_max = array[j];
				current_maxIndex = j;
			}
		}
		if (current_maxIndex != i) {
			array[current_maxIndex] = array[i];
			array[i] = current_max;
		}
	}
}
int main() {
	StopWatch watch;
	srand(time(0));
	for (int i = 0; i < 100000; i++) {
		list[i] = rand() % 100000;
	}
	cout << "selection sorting ...";
	watch.start();
	selectionSort(list);
	watch.stop();
	cout << endl << watch.getElapsedTime() << "ÃÊ!!" << endl;

	return 0;
}
