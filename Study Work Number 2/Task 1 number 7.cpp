#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>

using namespace std;

void sleep() {
	system("pause");
	cout << endl;
}

int isNatural(int var) {
	return var > 0 ? 1 : 0;
}

float getFraction(float val) {
	float intPart = 0;
	return modff(val, &intPart);
}

float correctly(char nameVariable, char type, int lim) {

	//
	// type == 'f', float numbers
	// else integer numbers
	//
	// lim == 0, any numbers
	// lim == 1, natural numbers
	int stop = 0;
	float number = 0;
	cout << " " << nameVariable << " = ";
	while (1) {
		stop = scanf_s("%f", &number);
		fflush(stdin);
		if (stop == 1) {
			if (type == 'i')
			{
				if (getFraction(number) == 0) {
					if (isNatural(number) == 1) {
					
						printf("\n Variable %c correctly! \n\n", nameVariable);
						break;
					}
					else {
						printf("Variable %c not correctly! Not natural. Try again. \n%c = ", nameVariable, nameVariable);
					}

				}
				else
				{
					printf("Variable %c not correctly! Check type (need int). Try again. \n%c = ", nameVariable, nameVariable);
				}
			}
			else {
				printf("\n Variable %c correctly! \n\n", nameVariable);
				break;
			}
		}
		else {
					while (getc(stdin) != '\n');
			printf("Variable %c not correctly! Try again. \n%c = ", nameVariable, nameVariable);
		}
	}

	sleep();
	return number;
}

void printLogo(int task) {
	//system("cls");
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

float getP(float a, int n) {
	float sum = 0;
	float tmpP = 0;
	cout << endl;
	for (int i = 1; i <= n; i++) {
		tmpP = (1 / pow(a, 2 * i - 2));
		cout << "addend" << i << " = " << tmpP << endl;
		sum = sum + tmpP;
	}
	cout << endl;
	return sum;
}

float getSumGeometricProgression(float a, int n) {
	return (pow(a, 2 - 2 * n) * (pow(a, 2 * n) - 1)) / (pow(a, 2) - 1);
}

int main()
{
	while (true) {
		int task = 7;

		myCls(task);
		cout << "Given real number 'a' and a natural number 'n'." << endl << "Calculate (use cyclic) P = sum 1/a^(2n-2)" << endl << endl;

		float a = 0;
		cout << " Enter real number a (float)" << endl;
		a = correctly('a', 'f', 0);// name: a; type: float, limit: unlimit

		int  n = 0;
		cout << " Enter natural number n (integer)" << endl;
		n = correctly('n', 'i', 1);// name: n; type: int, limit: natural
		
		myCls(task);
		cout << " denominator a = " << a << endl;
		cout << " degree n = " << n << endl;

		float pCyclic = getP(a, n);
		float pGeometric = getSumGeometricProgression(a, n);

		cout << " -> Pc (cyclic) = " << pCyclic << endl;
		cout << " -> Pg (sum geometric progression) = " << pGeometric << endl;

		pCyclic == pGeometric ?  cout << "All right. Pc == Pg" : cout << "Program error. Pg != Pc";

		jobDone();
	}
}

