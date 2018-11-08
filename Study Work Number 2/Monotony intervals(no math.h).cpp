#define VAL_EPS 0.0000001
#define VAL_PI 3.141592653589

#include <fstream> // LOG
#include <iostream>
//#include "math.h"

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

void printTable(double x, double y, double dy) {
	printf("\t%5f\t", x);
	printf("\t%5f\t", y);
	printf("\t%5f\t", dy);
	printf("\n\n");
}

//------------------------------------
//------------   math	--------------
//------------------------------------

double my_pow(double x, int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return x;
	else if (n % 2 == 0)
		return my_pow(x * x, n / 2);
	else
		return my_pow(x * x, n / 2)*x;
}

double my_fabs(double a)
{
	if (a < 0) {
		return -a;
	}
	return a;
}

double my_cos(double x)
{
	double sum = 0; // Òóò êîïèì ñóììó
	double an = 1;// Òóò õðàíèì N-ûé ÷ëåí ðÿäà (íà÷àëüíîå çíà÷åíèå an)
	int n = 0; // íà÷àëüíîå çíà÷åíèå n

	while (my_fabs(an) > VAL_EPS)
		// Ñóììèðîâàòü áóäåì ïîêà ÷ëåí ðÿäà an íå ñòàíåò äîñòàòî÷íî ìàëåíüêèì ïî ìîäóëþ
	{
		sum += an; // ñóììèðóåì î÷åðåäíîé ÷ëåí ðÿäà
		n++;
		an *= (-x * x) / (2 * n*(2 * n - 1)); // ïåðåñ÷èòûâàåì a(n) ÷åðåç a(n-1)
	}
	return sum; // ïîëó÷èâøàÿñÿ ñóììà
}

double my_arctg(double x) {

	if (x < 1) {
		return -VAL_PI / 2;
	}

	if (x > 1) {
		return VAL_PI / 2;
	}

	double sum = 0; // Òóò êîïèì ñóììó
	double an = x;// Òóò õðàíèì N-ûé ÷ëåí ðÿäà (íà÷àëüíîå çíà÷åíèå an)

	for (int n = 0; VAL_EPS < my_fabs(an); n = n + 1) //n -  íà÷àëüíîå çíà÷åíèå n
		// Ñóììèðîâàòü áóäåì ïîêà ÷ëåí ðÿäà an íå ñòàíåò äîñòàòî÷íî ìàëåíüêèì ïî ìîäóëþ
	{
		sum += an; // ñóììèðóåì î÷åðåäíîé ÷ëåí ðÿäà
		an *= (-1)*x*x*(2 * n + 1) / (2 * n + 3.0); // ïåðåñ÷èòûâàåì a(n) ÷åðåç a(n-1)
	}
	return sum; // ïîëó÷èâøàÿñÿ ñóììà
}

double my_sin(double x)
{
	double s, an;
	int n;
	n = 1;
	an = x;
	s = 0;
	while (my_fabs(an) > VAL_EPS)
	{
		s += an;
		n++;
		an *= -x * x / (2.*n - 1.0) / (2.0*n - 2.0);
	}
	return s;
}
//------------------------------------

double calcY(double x) {
	if (x < 0) {
		return my_arctg(x);
	}
	else{
		return my_cos(x);
	}
}

double calc_dY(double x) {
	if (x < 0) {
		return 1 / (1 + my_pow(x, 2));
	}
	else {
		return -my_sin(x);
	}
}

void createLogFile(double b, double a, double h) {
	std::ofstream outY, out_dY, outX;
	outY.open("D:\\logY.txt");
	out_dY.open("D:\\log_dY.txt");
	outX.open("D:\\logX.txt");
	for (double x = a; x < b; x += h) {
		double tmpY = calcY(x);
		double tmp_dY = calc_dY(x);
		if (outY.is_open()) {
			outY << tmpY << std::endl;
			out_dY << tmp_dY << std::endl;
			outX << x << std::endl;
		}
	}
	outY.close();
	out_dY.close();
}

int main() {
	while (true)
	{
		int task = 7;

		myCls(task);
		cout
			<< "Build a table of values of the function y = f (x) on the interval [a, b] with a step h" << endl
			<< "Determine whether the function is monotonous" << endl
			<< "f(x) = arctg(x)		  		 if (x < 0)" << endl
			<< "f(x) = cos(x)		  		 if (0 <=  x  < 1)" << endl
			<< "f(x) = min{arctg(x), cos(x)} if (x >= 1)" << endl << endl;

		double b = 0, a = 0, h = 0;

		cout << " a = ";
		cin >> a;

		cout << " b = ";
		cin >> b;

		cout << " h = ";
		cin >> h;

		cout << endl << " a = " << a;
		cout << endl << " b = " << b;
		cout << endl << " h = " << h;

		printHeadTable();

		bool isMonotone = true;
		double tmp_dY = calc_dY(a);
		int firstDerivative = tmp_dY / my_fabs(tmp_dY);

		for (double x = a; x < b; x += h) {
			double tmpY = calcY(x);
			double tmp_dY = calc_dY(x);
			printTable(x, tmpY, tmp_dY);

			if (firstDerivative != tmp_dY / my_fabs(tmp_dY)) {
				isMonotone = false;
				firstDerivative = tmp_dY / my_fabs(tmp_dY);
			}
		}

		if (isMonotone) {
			cout << endl << " function is monotone " << endl;
		}
		else {
			cout << endl << " function is NOT monotone " << endl;
		}

		createLogFile(b, a, h);
		jobDone();
	}
}
