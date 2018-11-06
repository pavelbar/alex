
#include <iostream>
#include "math.h"

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

void printHeadTable() {
	printf("\t x \t");
	printf("\t\t y(x) \t");
	printf("\t\t derivative\t");
	printf("\n\n");
}

void printTable(double x, double y, int dy) {
	printf("\t%5f\t", x);
	printf("\t%5f\t", y);
	printf("\t%5d\t", dy);
	printf("\n\n");
}

double calcY(double x) {
	if (x < 0) {
		return atan(x);
	}
	if ((x >= 0) && (x < 1)) {
		return cos(x);
	}
	if (x >= 1) {
		if (cos(x) < atan(x)) {
			return cos(x);
		}
		else {
			return atan(x);
		}
	}
}

double calc_dY(double x) {
	if (x < 0) {
		return -1 / (1 + pow(x, 2));
	}
	if ((x >= 0) && (x < 1)) {
		return -sin(x);
	}
	if (x >= 1) {
		if (cos(x) < atan(x)) {
			return -sin(x);
		}
		else {
			return -1 / (1 + pow(x, 2));
		}
	}
}

int checkDerivative(double dy) {
	if (dy > 0) {
		return 1;
	}
	else if (dy == 0) {
		return 0;
	}
	else {
		return -1;
	}
}

int main() {
	while (true)
	{
		int task = 7;
		double RIGHT_LIMIT = 0, LEFT_LIMIT = 0, DELTA_X = 0;

		myCls(task);
		cout
			<< "Build a table of values of the function y = f (x) on the interval [a, b] with a step h" << endl
			<< "Determine whether the function is monotonous" << endl
			<< "f(x) = arctg(x)		  		 if (x < 0)" << endl
			<< "f(x) = cos(x)		  		 if (0 <=  x  < 1)" << endl
			<< "f(x) = min{arctg(x), cos(x)} if (x >= 1)" << endl << endl;

		cout << " a = ";
		cin >> LEFT_LIMIT;

		cout << " b = ";
		cin >> RIGHT_LIMIT;

		cout << " h = ";
		cin >> DELTA_X;

		//cout << " LEFT_LIMIT = " << LEFT_LIMIT;
		//cout << " RIGHT_LIMIT = " << RIGHT_LIMIT;
		//cout << " DELTA_X = " << DELTA_X;

		printHeadTable();

		bool isMonotone = true;
		int firstDerivative = checkDerivative(calc_dY(LEFT_LIMIT));

		for (double x = LEFT_LIMIT; x < RIGHT_LIMIT + DELTA_X; x += DELTA_X) {
			double tmpY = calcY(x);
			printTable(x, tmpY, checkDerivative(calc_dY(x)));
			if (firstDerivative != checkDerivative(calc_dY(x))) {
				isMonotone = false;
			}
		}

		if (isMonotone) {
			cout << endl << " function is monotone " << endl;
		}
		else {
			cout << endl << " function is NOT monotone " << endl;
		}

		jobDone();
	}
}
