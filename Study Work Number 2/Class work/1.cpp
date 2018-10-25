#include <iostream>

using namespace std;

void printLogo(int task) {
	printf("************************************************************\n"
		"* Nizhniy Novgorod Technical University                    *\n");
	printf("* Study work number 2. Task number %d.                      *\n", task);
	printf("* Performed student 18 - IVT - 2. Kornilov Alexey          *\n"
		"************************************************************\n");
}

void sleep() {
	system("pause");
	cout << endl;
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

int correctly(char nameVariable) {
	printf("\n%c = ", nameVariable);
	int stop = 0;
	int answer = 0;

	while (stop != 1) {
		stop = scanf_s("%d", &answer);
		fflush(stdin);
		if (stop != 1) {
			while (getc(stdin) != '\n');
			printf("Variable %c not correctly! Try again. \n%c = ", nameVariable, nameVariable);
		}
	}

	return answer;
}


int main() {
	while (true) {
		int task = 3;
		myCls(task);
		cout <<
			"1. Find the sum of positive numbers entered from the keyboard (the user can enter negative values)."
			"The signal to the calculation of the result is the input of zero, symbolizing the end of the sequence.\n";

		int number = 1;
		int sum = 0;

		number = correctly('a');
		sum += number;
		while (number != 0)
		{
			number = correctly('a');
			sum += number;
		}

		cout << endl << "Sum = " << sum << endl;

		sleep();
	}
	return 0;
}
