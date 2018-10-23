#define LEFT_LIMIT 0.05
#define RIGHT_LIMIT 1.55
#define DELTA_X 0.05

#include <iostream>
#include <vector>
#include "math.h"
#include <algorithm> //max_element, min_element
#include <numeric>   //accumulate

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

void printTable(const vector<double> &vectorX, const vector<double> &vectorY) {
	printf("\t    x \t");
	printf("\t   y(x) \t");
	printf("\n\n");
	for (int i = 0; i < vectorX.size(); i++)
	{
		printf("\t%5f\t", vectorX[i]);
		printf("\t%5f\t", vectorY[i]);

		printf("\n\n");
	}
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

		vector<double> vectorX, vectorY;    //Пустой вектор v_str
		for (double x = LEFT_LIMIT; x < RIGHT_LIMIT + DELTA_X; x += DELTA_X) {
			vectorX.push_back(x);
			vectorY.push_back(calcY(x));
		}

		printTable(vectorX, vectorY);

		vector<double>::const_iterator maxY = max_element(vectorY.begin(), vectorY.end());
		double xForMaxY = vectorX[maxY - vectorY.begin()];

		vector<double>::const_iterator minY = min_element(vectorY.begin(), vectorY.end());
		double xForMinY = vectorX[minY - vectorY.begin()];

		cout << " ->Maximum value y(" << xForMaxY << ") = " << *maxY << endl;
		cout << " ->Minimum value y(" << xForMinY << ") = " << *minY << endl;
		cout << " ->Average = " << accumulate(vectorY.begin(), vectorY.end(), 0.0) / vectorY.size() << endl;

		jobDone();
	}
}
