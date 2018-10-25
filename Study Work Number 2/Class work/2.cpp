#define LEFT_LIMIT -50
#define RIGHT_LIMIT 200

#include <iostream>

using namespace std;

void sleep() {
	system("pause");
	cout << endl;
}

void printLogo(int task) {
	printf("************************************************************\n"
		"* Nizhniy Novgorod Technical University                    *\n");
	printf("* Study work number 2. Task number %d.                      *\n", task);
	printf("* Performed student 18 - IVT - 2. Kornilov Alexey          *\n"
		"************************************************************\n");
}

void myCls(int task) {
	system("cls");
	printLogo(task);
}

void jobDone() {
	cout << endl;
	puts("\nJob done.");
	cout << endl;
	sleep();
}

int getLastDigit(int number) {
	return number % 10;
}

int isMultipleFive(int number) {
	return number % 5 == 0 ? 1 : 0;
}

int isMultipleEight(int number) {
	return number % 8 == 0 ? 1 : 0;
}


int main() {
	while (1) {
		int task = 3;
		myCls(task);
		int sum = 0;
		for (int i = LEFT_LIMIT + 1; i < RIGHT_LIMIT; i++) {
			if ((isMultipleFive(i)) && (isMultipleEight(i)) && ((getLastDigit(i) == 5) || (getLastDigit(i) == 0))) {
				cout << endl << "Addend: " << i;
				sum += i;
			}
		}
		cout << endl << endl << "Sum = " << sum;
		jobDone();
	}
}
