#define LEFT_LIMIT 0.05
#define RIGHT_LIMIT 1.55
#define DELTA_X 0.05

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
	printf("\n\n");
}

void printTable(double x, double y) {
	printf("\t%5f\t", x);
	printf("\t%5f\t", y);
	printf("\n\n");
}

double calcY(double x) {
	return (10 / pow(x, 5)) - (3 / x) - sqrt(pow(x, 3)) + 243;
}

int main() {
	while (true)
	{
		int task = 7;

		myCls(task);
		cout
			<< "Build a table of values of the function y = f (x) on the interval x [0.05; 1.55] with a step ∆x = 0.05." << endl
			<< "Find the minimum and maximum value, which is applied by the function on the specified interval." << endl
			<< "Calculate the arithmetic average value for the generated table of values of the function f (xi)." << endl
			<< "y = 3^5-(3/x)-sqrt(x^3)+(10/x^5) = (10/x^5)-(3/x)-sqrt(x^3)+243" << endl << endl;

		int  len = (1.55 - 0.05) / 0.05;

		double maxY = calcY(LEFT_LIMIT);
		double  xForMaxY = LEFT_LIMIT;

		double minY = calcY(LEFT_LIMIT);
		double  xForMinY = LEFT_LIMIT;

		double sum = 0;

		printHeadTable();

		for (double x = LEFT_LIMIT; x < RIGHT_LIMIT + DELTA_X; x += DELTA_X) {
			double tmpY = calcY(x);
			sum += tmpY;

			printTable(x, tmpY);

			if (maxY < tmpY) {
				maxY = tmpY;
				xForMaxY = x;
			}

			if (minY > tmpY) {
				minY = tmpY;
				xForMinY = x;
			}

		}

		cout << " ->Maximum value y(" << xForMaxY << ") = " << maxY << endl;
		cout << " ->Minimum value y(" << xForMinY << ") = " << minY << endl;
		cout << " ->Average = " << sum / len << endl;

		jobDone();
	}
}
