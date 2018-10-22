#define FOOTS_IN_KILOMMETER 0.45
#define METERS_IN_KILOMMETER 1000
#define PI_VAL 3.14
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>
#include <math.h>


using namespace std;

/*
 * Если целое число М делится нацело на целое N, то вывести на экран частное от деления,
 * в противном случае вывести сообщение «M на N не делится без остатка».
 */

void myCls(int task) {
	system("cls");
	printf("************************************************************\n"
		"* Nizhniy Novgorod Technical University                    *\n");
	printf("* Study work number 2. Task number %d.                      *\n", task);
	printf("* Performed student 18 - IVT - 2. Kornilov Alexey          *\n"
		"************************************************************\n");
}

int getLengthNumber(int numb) {
	int count = 0;

	if (numb == 0) {
		return 1;
	}

	while (numb) {
		numb /= 10;
		count++;
	}
	return count;
}

int checkLen(int var, int len) {
	int res = 0;
	if (len == 0) {
		res = 1;
	}
	else if (getLengthNumber(var) == len) {
		res = 1;
	}
	return res;
}

int checkLimit(int var, int lim) {
	int res = 0;
	//case
	if (lim == 0) {
		res = 1;
	}
	if (lim == 1) {
		if (var > 0) {
			res = 1;
		}
	}
	if (lim == 2) {
		if (var >= 0) {
			res = 1;
		}
	}
	if (lim == 3) {
		if (var < 0) {
			res = 1;
		}
	}
	if (lim == 4) {
		if (var <= 0) {
			res = 1;
		}
	}
	if (lim == 5) {
		if (var != 0) {
			res = 1;
		}
	}
	return res;
}

void sleep() {
	printf(" _Press ENTER");
	getchar();
}

int correctly(char nameVariable, int len, int lim) {
	puts(" =============================\n"
		" ||           HELP          ||\n"
		" =============================\n"
		" || len - length            ||\n"
		" || ========================||\n"
		" || lim - limit             ||\n"
		" || 0: off (unlimit)        ||\n"
		" || 1: x >  0;              ||\n"
		" || 2: x >= 0;              ||\n"
		" || 3: x <  0;              ||\n"
		" || 4: x <= 0               ||\n"
		" || 5: x != 0               ||\n"
		" =============================");
	printf("    (INT variable, len =  %d | limit = %d)\n\n", len, lim);
	printf("%c = ", nameVariable);

	int stop = 0;
	int answer = 0;

	while (1) {
		stop = scanf("%d", &answer);
		fflush(stdin);
		if (stop == 1) {
			if (checkLen(answer, len) == 1) {
				if (checkLimit(answer, lim) == 1) {
					printf("\n Variable %c correctly! \n\n", nameVariable);
					break;
				}
				else {
					printf("Variable %c not correctly! Check restrict (limit != %d). Try again. \n%c = ", nameVariable,
						lim, nameVariable);
				}
			}
			else {
				printf("Variable %c not correctly! Check length (length != %d). Try again. \n%c = ", nameVariable, len, nameVariable);
			}
		}
		else {
			printf("Variable %c not correctly! Check type (INT variable). Try again. \n%c = ", nameVariable, nameVariable);
		}
	}

	sleep();
	return answer;
}

void jobDone() {
	puts("\nJob done.");
	sleep();
}

//###############################################################
//################ Solution Functions ###########################
//###############################################################

int isEven(int number) {
	return number % 2 == 0 ? 1 : 0;
}


int getLastDigit(int number) {
	return number % 10;
}

int isOdd(int number) {
	return !!!isEven(number);
}

double footsToKm(int distance) {
	return distance * FOOTS_IN_KILOMMETER;
}

double msToKm(int speed) {
	return speed / METERS_IN_KILOMMETER;
}

double getAreaCircle(int radius) {
	return PI_VAL * radius * radius;
}

double getAreaSquare(int length) {
	return length * length;
}

double getRadiusCircleFromArea(int area) {
	return sqrt(area / PI_VAL);
}


double getLengthSquareFromArea(int area) {
	return sqrt(area);
}


double getDiametrCircleFromRadius(double radius) {
	return radius * 2;
}

int getFirstDigit(int number) {
	return number / pow(10, getLengthNumber(number) - 1);
}

int getDigitInPos(int number, int pos) {//0,1,2....
	number = abs(number);
	int shift = number / pow(10, getLengthNumber(number) - 1 - pos);
	return shift % 10;
}

//###############################################################
//###################### SOLUTIONS ##############################
//###############################################################

void solution1(int N, int M) {     //Task 1
	if (M % N == 0) {
		printf("%d\n", M / N);
	}
	else {
		puts("Error. Not null\n");
	}
}

void task1() {
	// Если целое число М делится нацело на целое N, то вывести на экран частное от деления,
	// в противном случае вывести сообщение «M на N не делится без остатка».
	int task = 1;

	myCls(task);
	int M = 0;
	printf("--> Enter dividend M\n\n");//делимое
	M = correctly('M', 0, 0);

	myCls(task);
	int N = 0;
	printf("--> Enter divider N\n\n");//делитель
	N = correctly('N', 0, 5);

	myCls(task);
	printf("N = %d\nM = %d \n M / N = ", M, N);

	solution1(N, M);

	jobDone();
}

void solution2(int A, int B) {       //Task 2
	if (B % A == 0) {
		puts("\n\nAll right. A is divider for B");
	}
	else {
		puts("\n\nError. A is NOT divider for B");
	}
}

//

void task2() {
	// Является ли число А делителем Б
	int task = 2;

	myCls(task);
	int B = 0;
	printf("Enter dividend B (int)\n\n");//делимое
	B = correctly('B', 0, 0);

	myCls(task);
	int A = 0;
	printf("Enter divider A (int)\n\n");//делитель
	A = correctly('A', 0, 5);

	myCls(task);
	printf("A = %d\nB = %d \n B / A", A, B);

	solution2(A, B);

	jobDone();
}

//

void solution3(int number) {     //Task 3
	isEven(number) ? puts(" All right. A is Even") : puts(" Error. A is NOT Even");

	getLastDigit(number) == 4 ? puts(" All right. Lost is 4") : puts(" Error. A is NOT 4");
}

void task3() {
	// Дано целое число. Определить является ли оно четным и оканчивается ли оно на 4.
	int task = 3;

	myCls(task);
	int A = 0;
	printf("Enter digit A (int)\n\n");
	A = correctly('A', 0, 0);

	myCls(task);
	printf("A = %d\n", A);

	solution3(A);

	jobDone();
}

//

void solution4(int number) {     //Task 4
	isOdd(number) ? puts(" All right. A is odd") : puts(" Error. A is NOT odd");

	getLastDigit(number) == 7 ? puts(" All right. Lost is 7") : puts(" Error. Lost is not 7");
}

void task4() {
	// Дано целое число. Определить является ли оно НЕчетным и оканчивается ли оно цифрой 7.
	int task = 4;

	myCls(task);
	int A = 0;
	printf("Enter digit A (int)\n\n");
	A = correctly('A', 0, 0);

	myCls(task);
	printf("A = %d\n", A);

	solution4(A);

	jobDone();
}

//

void solution5(int number) {       //Task 5
	if (isEven(getLastDigit(number))) {
		puts(" All right. Last from A is Even");
	}
	else {
		puts(" Error. Last from A is NOT Even");
	}
}

void task5() {
	// Дано целое число. Определить оканчивается ли оно четной цифрой (составное условие не использовать).
	int task = 5;

	myCls(task);
	int A = 0;
	printf("Enter digit A (int)\n\n");
	A = correctly('A', 0, 0);

	myCls(task);
	printf("A = %d\n", A);

	solution5(A);

	jobDone();
}

//

void solution6(int yearBirth, int monthBirth, int yearNow, int monthNow) {       //Task6
	int age = yearNow - yearBirth;
	if (monthNow < monthBirth) {
		age--;
	}

	printf("\n Age = %d\n", age);
}

void task6() {
	//  Известны год и месяц рождения человека, а также год и номер месяца сегодняшнего дня. Определить возраст человека,
	//  число полных лет. В случае совпадения указанных месяцев считать, что прошел полный год.
	int task = 6;

	myCls(task);
	int yearBirth = 0;
	printf("Enter year of birth (int>0)\n\n");
	yearBirth = correctly('A', 0, 2);

	myCls(task);
	int monthBirth = 0;
	printf("Enter month of birth (int>=0)\n\n");
	monthBirth = correctly('B', 0, 2);

	myCls(task);
	int yearNow = 0;
	printf("Enter year now (int>=0)\n\n");
	yearNow = correctly('C', 0, 2);

	myCls(task);
	int monthNow = 0;
	printf("Enter month now (int>=0)\n\n");
	monthNow = correctly('D', 0, 2);

	myCls(task);
	printf("yearBirth = %d\nmonthBirth = %d\nyearNow = %d\nmonthNow = %d", yearBirth, monthBirth, yearNow,
		monthNow);

	solution6(yearBirth, monthBirth, yearNow, monthNow);

	jobDone();
}

//

void solution7(int km, int foot) {       //Task7
	double valFootsToKm = footsToKm(foot);

	printf("\n distance 2 (KM) = %f\n", valFootsToKm);

	if (km < valFootsToKm) {
		puts(" distance 1 < distance 2");
	}
	else {
		puts(" distance 1 >= distance 2");
	}
}

void task7() {
	// Известны два расстояниея. Одно в КМ другое в футах. (1км = 0.45 фута). Какое расстояние меньше?
	int task = 7;

	myCls(task);
	double distanceOneKm = 0;
	printf("Enter distance 1 (Km) (int>0)\n\n");
	distanceOneKm = correctly('A', 0, 1);

	myCls(task);
	double distanceTwoFoot = 0;
	printf("Enter distance 2 (Foot) (int>0)\n\n");
	distanceTwoFoot = correctly('B', 0, 1);

	system("cls");
	printf("distance 1 (KM) = %f\ndistance 2 (Foot) = %f\n", distanceOneKm, distanceTwoFoot);

	solution7(distanceOneKm, distanceTwoFoot);

	jobDone();
}

//

void solution8(int kmH, int mS) {        //Task 8
	double valMsToKm = msToKm(mS);
	printf("\n speed 2 (Km/H) = %f\n", valMsToKm);

	if (labs(kmH) < valMsToKm) {
		puts(" speed 1 < speed 2");
	}
	else {
		puts(" speed 1 >= speed 2");
	}
}

void task8() {
	// Известны две скорости. Одна в КМ/ч, другая в М/С. Какая скорость больше?
	int task = 8;

	myCls(task);
	double speedOneKmH = 0;
	printf("Enter speed 1 (Km/H) (int)\n\n");
	speedOneKmH = correctly('A', 0, 0);

	myCls(task);
	double speedTwoMs = 0;
	printf("Enter speed 2 (M/s) (int)\n\n");
	speedTwoMs = correctly('B', 0, 0);

	myCls(task);
	printf("speed 1 (Km/H) = %f\nspeed 2 (M/s) = %f\n", speedOneKmH, speedTwoMs);

	solution8(speedOneKmH, speedTwoMs);

	jobDone();
}

//
void solution9(int radius, int length) {      //Task 9
	double valAreaCircle = getAreaCircle(radius);
	double valAreaSquare = getAreaSquare(length);

	printf("\n Area Circle = %f\n Area Square = %f\n", valAreaCircle, valAreaSquare);

	if (valAreaCircle < valAreaSquare) {
		puts(" Area Circle < Area Square");
	}
	else {
		puts(" Area Circle >= Area Square");
	}
}

void task9() {
	// Даны радиус круга и сторона квадрата. У какой фигуры площадь больще?
	int task = 9;

	myCls(task);
	double radius = 0;
	printf("Enter radius for circle (int > 0)\n\n");
	radius = correctly('A', 0, 1);

	myCls(task);
	double lenght = 0;
	printf("Enter lenght for square (int > 0)\n\n");
	lenght = correctly('B', 0, 1);

	myCls(task);
	printf("radius for circle = %f\nlenght for square = %f\n", radius, lenght);

	solution9(radius, lenght);

	jobDone();
}

//

void solution10(int areaCircle, int areaSquare) {      //Task 10
	double valRadiusCircle = getRadiusCircleFromArea(areaCircle);
	double valDiametrCircle = getDiametrCircleFromRadius(valRadiusCircle);
	double valLengthSquare = getLengthSquareFromArea(areaSquare);

	printf("\n radius Circle = %f", valRadiusCircle);
	printf("\n diametr Circle = %f", valDiametrCircle);
	printf("\n length Square = %f", valLengthSquare);

	if (valDiametrCircle <= valLengthSquare) {
		puts("\n\n All right. Circle in Square");
	}
	else {
		puts("\n\n Error. Lite Square and big Circle");
	}
}

void task10() {
	// Известные площади круга и квадрата. Определить уместится ли круг в квадрате
	int task = 10;

	myCls(task);
	double areaCircle = 0;
	printf("Enter area for circle (int > 0)\n\n");
	areaCircle = correctly('A', 0, 1);

	myCls(task);
	double areaSquare = 0;
	printf("Enter area for square (int > 0)\n\n");
	areaSquare = correctly('B', 0, 1);

	myCls(task);
	printf("Area for circle = %f\nArea for square = %f\n", areaCircle, areaSquare);

	solution10(areaCircle, areaSquare);

	jobDone();
}

//

void solution11(int num) { //Task 11
	int rightDigit = getLastDigit(num);
	int leftDigit = getFirstDigit(num);

	printf(" Left Digit =%d\n", leftDigit);
	printf(" Right Digit =%d\n", rightDigit);

	if (leftDigit < rightDigit) {
		puts(" Left Digit < Right Digit");
	}
	else {
		puts(" Left Digit >= Right Digit");
	}
}

void task11() {
	// Дано двухзначное число. Определить какая из его цифр больше 1 или 2
	int task = 11;

	myCls(task);
	int num = 0;
	printf("Enter digit (int, length = 2)\n\n");
	num = correctly('A', 2, 0);

	myCls(task);
	printf("digit = %d\n", num);

	solution11(num);

	jobDone();
}

//

void solution12(int num) { //Task 12
	int rightDigit = getLastDigit(num);
	int leftDigit = getFirstDigit(num);

	printf(" Left Digit =%d\n", leftDigit);
	printf(" Right Digit =%d\n", rightDigit);

	if (leftDigit == rightDigit) {
		puts(" All right. Left Digit equal Right Digit");
	}
	else {
		puts(" Error. Left Digit NOT equal Right Digit");
	}
}

void task12() {
	// Дано двузначное число. Определить, одинаковы ли его цифры.
	int task = 12;

	myCls(task);
	int num = 0;
	printf("Enter digit (int, length = 2)\n\n");
	num = correctly('A', 2, 0);

	myCls(task);
	printf("digit = %d\n", num);

	solution12(num);

	jobDone();
}

//

void solution13(int num) { //Task 13
	int rightDigit = getLastDigit(num);
	int leftDigit = getFirstDigit(num);

	int squaredNumber = num * num;
	int result = 4 * (leftDigit * leftDigit * leftDigit + rightDigit * rightDigit * rightDigit);

	printf(" Left Digit =%d\n", leftDigit);
	printf(" Right Digit =%d\n", rightDigit);
	printf(" squared Number =%d\n", squaredNumber);
	printf(" quadruple sum of cubes =%d\n", result);

	if (squaredNumber == result) {
		puts(" All right. Equal");
	}
	else {
		puts(" Error. NOT Equal");
	}
}

void task13() {
	// Дано двузначное число. Определить, равен ли квадрат этого числа учетверенной сумме кубов его цифр.
	int task = 13;

	myCls(task);
	int num = 0;
	printf("Enter digit (int, length = 2)\n\n");
	myCls(task);
	num = correctly('A', 2, 0);

	myCls(task);
	printf("digit = %d\n", num);

	solution13(num);

	jobDone();
}

//

void solution14(int num) { //Task 14
	int rightDigit = getLastDigit(num);
	int leftDigit = getFirstDigit(num);
	int sum = rightDigit + leftDigit;


	printf(" Left Digit =%d\n", leftDigit);
	printf(" Right Digit =%d\n", rightDigit);
	printf(" Sum left and right digit =%d\n", sum);

	if (getLengthNumber(sum) == 2) {
		puts(" All right. Sum is two-digit number");
	}
	else {
		puts(" Error. Sum is NOT two-digit number");
	}
}

void task14() {
	//  Дано двузначное число. Определить, является ли сумма его цифр двузначным числом
	int task = 14;

	myCls(task);
	int num = 0;
	printf("Enter digit (int, length = 2)\n\n");
	num = correctly('A', 2, 0);

	myCls(task);
	printf("digit = %d\n", num);

	solution14(num);

	jobDone();
}

//

void solution15(int num) { //Task 15
	int rightDigit = getLastDigit(num);
	int leftDigit = getFirstDigit(num);
	int sum = rightDigit + leftDigit;


	printf(" Left Digit =%d\n", leftDigit);
	printf(" Right Digit =%d\n", rightDigit);
	printf(" Sum left and right digit =%d\n", sum);

	if (sum % 3 == 0) {
		puts(" All right. Sum is multiple of three");
	}
	else {
		puts(" Error. Sum is NOT multiple of three");
	}
}

void task15() {
	//Дано двузначное число. Определить, кратна ли трем сумма его цифр.
	int task = 15;

	myCls(task);
	int num = 0;
	printf("Enter digit (int, length = 2)\n\n");
	num = correctly('A', 2, 0);

	myCls(task);
	printf("digit = %d\n", num);

	solution15(num);

	jobDone();
}

//

void solution16(int num) { //Task 16
	int rightDigit = getLastDigit(num);
	int leftDigit = getFirstDigit(num);

	printf(" Left Digit =%d\n", leftDigit);
	printf(" Right Digit =%d\n", rightDigit);

	if (rightDigit == leftDigit) {
		puts(" All right. Digit is palindrome");
	}
	else {
		puts(" Error. Digit is NOT palindrome");
	}
}

void task16() {
	//  Дано трехзначное число. Выяснить, является ли оно палиндромом («перевертышем»),
	//  то есть числом, десятичная запись которого читается одинаково слева направо и справа налево
	int task = 16;

	myCls(task);
	int num = 0;
	printf("Enter digit (int, length = 3)\n\n");
	num = correctly('A', 3, 0);

	myCls(task);
	printf("digit = %d\n", num);

	solution16(num);

	jobDone();
}

//

void solution17(int num) { //Task 17
	int leftDigit = getFirstDigit(num);
	int centerDigit = getDigitInPos(num, 1);
	int rightDigit = getLastDigit(num);

	int sum = rightDigit * rightDigit * rightDigit + leftDigit * leftDigit * leftDigit +
		centerDigit * centerDigit * centerDigit;
	int square = num * num;

	printf(" Left Digit =%d\n", leftDigit);
	printf(" Center Digit =%d\n", centerDigit);
	printf(" Right Digit =%d\n", rightDigit);
	printf(" Sum of cubes =%d\n", sum);
	printf(" Square =%d\n", square);

	if (sum == square) {
		puts(" All right. Sum and square is equal");
	}
	else {
		puts(" Error. Sum and square is not equal");
	}
}

void task17() {
	//  Дано трехзначное число. Выяснить, является ли оно палиндромом («перевертышем»),
	//  то есть числом, десятичная запись которого читается одинаково слева направо и справа налево
	int task = 17;

	myCls(task);
	int num = 0;
	printf("Enter digit (int, length = 3)\n\n");
	num = correctly('A', 3, 0);

	system("cls");
	printf("digit = %d\n", num);

	solution17(num);

	jobDone();
}

//

void solution18(int num) { //Task 18
	int leftDigit = getFirstDigit(num);
	int centerDigit = getDigitInPos(num, 1);
	int rightDigit = getLastDigit(num);
	int sum = rightDigit + leftDigit + centerDigit;

	printf(" Left Digit =%d\n", leftDigit);
	printf(" Right Digit =%d\n", rightDigit);
	printf(" Center Digit =%d\n", centerDigit);
	printf(" Sum =%d\n", sum);

	if (getLengthNumber(sum) == 3) {
		puts(" All right. Sum is Two Digit");
	}
	else {
		puts(" Error. Sum is NOT Two Digit");
	}
}

void task18() {
	//Дано трехзначное число. Определить, является ли сумма его цифр двузначным числом
	int task = 18;

	myCls(task);
	int num = 0;
	printf("Enter digit (int, length = 3)\n\n");
	num = correctly('A', 3, 0);

	myCls(task);
	printf("digit = %d\n", num);

	solution18(num);

	jobDone();
}

//

void solution19(int num) { //Task 19
	int leftDigit = getFirstDigit(num);
	int centerDigit = getDigitInPos(num, 1);
	int rightDigit = getLastDigit(num);
	int mult = rightDigit * leftDigit * centerDigit;

	printf(" Left Digit =%d\n", leftDigit);
	printf(" Right Digit =%d\n", rightDigit);
	printf(" Center Digit =%d\n", centerDigit);
	printf(" Multiplication =%d\n", mult);

	if (getLengthNumber(mult) == 2) {
		puts(" All right. Multiplication is Two Digit");
	}
	else {
		puts(" Error. Multiplication is NOT Two Digit");
	}
}

void task19() {
	//Дано трехзначное число. Определить, является ли произведение его цифр трехзначным числом
	int task = 19;

	myCls(task);
	int num = 0;
	num = correctly('A', 3, 0);

	myCls(task);
	printf("digit = %d\n", num);

	solution19(num);

	jobDone();
}

//

void solution20(int num) { //Task 20
	int leftDigit = getFirstDigit(num);
	int centerDigit = getDigitInPos(num, 1);
	int rightDigit = getLastDigit(num);
	int sum = rightDigit + leftDigit + centerDigit;

	printf(" Left Digit =%d\n", leftDigit);
	printf(" Right Digit =%d\n", rightDigit);
	printf(" Center Digit =%d\n", centerDigit);
	printf(" Sum =%d\n", sum);

	if (sum % 5 == 0) {
		puts(" All right. Sum is Multiple Of Five");
	}
	else {
		puts(" Error. Sum is NOT Multiple Of Five");
	}
}

void task20() {
	//Дано трехзначное число. Определить, кратна ли пяти сумма его цифр.
	int task = 20;

	myCls(task);
	int num = 0;
	printf("Enter digit (int, length = 3)\n\n");
	num = correctly('A', 3, 0);

	myCls(task);
	printf("digit = %d\n", num);

	solution20(num);

	jobDone();
}

//

void solution21(int num) { //Task 21
	int leftDigit = getFirstDigit(num);
	int centerDigit = getDigitInPos(num, 1);
	int rightDigit = getLastDigit(num);

	printf(" Left Digit =%d\n", leftDigit);
	printf(" Right Digit =%d\n", rightDigit);
	printf(" Center Digit =%d\n", centerDigit);

	if (leftDigit == rightDigit == centerDigit) {
		puts(" All right. All is equal");
	}
	else {
		puts(" Error. All is NOT equal");
	}
}

void task21() {
	//Дано трехзначное число. Верно ли, что все его цифры одинаковые?
	int task = 21;

	myCls(task);
	int num = 0;
	printf("Enter digit (int, length = 3)\n\n");
	num = correctly('A', 3, 0);

	myCls(task);
	printf("digit = %d\n", num);

	solution21(num);

	jobDone();
}

//

void solution22(int num) { //Task 22
	int leftDigit = getFirstDigit(num);
	int centerDigit = getDigitInPos(num, 1);
	int rightDigit = getLastDigit(num);

	printf(" Left Digit =%d\n", leftDigit);
	printf(" Right Digit =%d\n", rightDigit);
	printf(" Center Digit =%d\n", centerDigit);

	if ((leftDigit == centerDigit) || (leftDigit == rightDigit) || (centerDigit == rightDigit)) {
		puts(" All right. Have equal");
	}
	else {
		puts(" Error. Have NOT equal");
	}
}

void task22() {
	//Дано трехзначное число. Определить, есть ли среди его цифр одинаковые.
	int task = 22;

	myCls(task);
	int num = 0;
	printf("Enter digit (int, length = 3)\n\n");
	num = correctly('A', 3, 0);

	myCls(task);
	num = correctly('A', 3, 0);

	solution22(num);

	jobDone();
}

//

void solution23(int num) { //Task 23
	int leftDigit = getFirstDigit(num);
	int centerLeftDigit = getDigitInPos(num, 1);
	int centerRightDigit = getDigitInPos(num, 2);
	int rightDigit = getLastDigit(num);

	int leftSum = leftDigit + centerLeftDigit;
	int rightSum = rightDigit + centerRightDigit;

	printf(" Left Digit =%d\n", leftDigit);
	printf(" Center Left Digit =%d\n", centerLeftDigit);
	printf(" Center Right Digit =%d\n", centerRightDigit);
	printf(" Right Digit =%d\n", rightDigit);
	printf(" Left sum =%d\n", leftSum);
	printf(" Right sum =%d\n", rightSum);

	if (leftSum == rightSum) {
		puts(" All right. Left sum is equal for Right sum");
	}
	else {
		puts(" Error. Left sum is NOT equal for Right sum");
	}
}

void task23() {
	//Дано четырехзначное число. Определить, равна ли сумма двух первых его цифр сумме двух его последних цифр.
	int task = 23;

	myCls(task);
	int num = 0;
	printf("Enter digit (int, length = 4)\n\n");
	num = correctly('A', 4, 0);

	myCls(task);
	printf("digit = %d\n", num);

	solution23(num);

	jobDone();
}

//

void solution24(int num) { //Task 24
	int leftDigit = getFirstDigit(num);
	int centerLeftDigit = getDigitInPos(num, 1);
	int centerRightDigit = getDigitInPos(num, 2);
	int rightDigit = getLastDigit(num);

	int mult = rightDigit * leftDigit * centerRightDigit * centerLeftDigit;

	printf(" Left Digit =%d\n", leftDigit);
	printf(" Center Left Digit =%d\n", centerLeftDigit);
	printf(" Center Right Digit =%d\n", centerRightDigit);
	printf(" Right Digit =%d\n", rightDigit);

	printf(" Multiple =%d\n", mult);

	if (mult % 4 == 0) {
		puts(" All right. Number is Multiple Of Four");
	}
	else {
		puts(" Error. Number is NOT Multiple Of Four");
	}
}

void task24() {
	//Дано четырехзначное число. Определить, кратно ли четырем произведение его цифр.
	int task = 24;

	myCls(task);
	int num = 0;
	printf("Enter digit (int, length = 4)\n\n");
	num = correctly('A', 4, 0);

	system("cls");
	printf("digit = %d\n", num);

	solution24(num);

	jobDone();
}

//

void solution25(int number) {       //Task25
	int digit = number % 10;

	printf("\n Last digit = %d\n", digit);

	if (isOdd(digit)) {
		puts(" All right. Last Number Is Odd");
	}
	else {
		puts(" Error. Last Number Is NOT Odd");
	}
}

void task25() {
	//Дано натуральное число. Верно ли, что оно заканчивается нечетной цифрой?
	int task = 25;

	myCls(task);
	int number = 0;
	printf("Enter natural number (int>0)\n\n");
	number = correctly('A', 0, 1);

	myCls(task);
	printf("Natural number = %d\n", number);

	solution25(number);

	jobDone();
}

//

void solution26(int number) {       //Task26
	int digit = number % 10;

	printf("\n Last digit = %d\n", digit);

	if (isEven(digit) == 0) {
		puts(" All right. Last Number Is Even");
	}
	else {
		puts(" Error. Last Number Is NOT Even");
	}
}

void task26() {
	//Дано натуральное число. Верно ли, что оно заканчивается четной цифрой?
	int task = 26;

	myCls(task);
	int number = 0;
	printf("Enter natural number (int>0)\n\n");
	number = correctly('A', 0, 1);

	system("cls");
	printf("Natural number = %d\n", number);

	solution26(number);

	jobDone();
}


//###############################################################
//########################### MAIN ##############################
//###############################################################

int main() {
	while (1) {
		myCls(0);
		puts("\n ->Select task\n Task number 1 - Task number 50\n Input 0 for exit \n");

		{
		puts(
			"1. If an integer M is divisible by an integer N, then display the quotient, otherwise output the message M by N is not divisible without remainder.\n"

			"2. Determine whether the number A is a divisor for B.\n"

			"3. Given an integer. Determine whether it is even and ends with the number 4.\n"

			"4. Given an integer. Determine whether it is odd and ends with the number 7.\n"

			"5. Given an integer. Determine whether it ends in an even digit (do not use the compound condition).\n"

			"6. The year and month of birth of a person are known, as well as the year and month of today. Determine the age of the person, the number of full years. In case of coincidence of the specified months, assume that a full year has passed.\n"

			"7. Two distances are known: one in kilometers, the other in feet (1 foot = 0.45 m). What distance is less?\n"

			"8. Two speeds are known: one in kilometers per hour, the other in meters per second. Which speed is higher?\n"

			"9. Given the radius of the circle and the side of the square. Which figure has bigger area?\n"

			"10. The areas of a circle and a square are known. Determine whether the circle will fit in a square.\n"

			"11. Given a two-digit number. Determine which of its numbers is greater, first or second.\n"

			"12. Given a two-digit number. Determine whether its numbers are the same.\n"

			"13. Given a two-digit number. Determine whether the square of this number is equal to the quadruple sum of the cubes of its numbers.\n"

			"14. Given a two-digit number. Determine whether the sum of its digits is a two-digit number.\n"

			"15. Given a two-digit number. Determine whether the sum of its digits is a multiple of three.\n"

			"16. Given a three-digit number. Find out whether it is a palindrome (flip), that is, a number whose decimal notation is read equally from left to right and from right to left.\n"

			"17. Given a three-digit number. Determine whether the square of this number is equal to the sum of the cubes of its numbers.\n"

			"18. Given a three-digit number. Determine whether the sum of its digits is a two-digit number.\n"

			"19. Given a three-digit number. Determine whether the product of its numbers is a three-digit number.\n"

			"20. Given a three-digit number. Determine whether five is a multiple of the sum of its digits.\n"

			"21. Given a three-digit number. Is it true that all his numbers are the same?\n"

			"22. Given a three-digit number. Determine whether among his numbers are the same.\n"

			"23. Given a four-digit number. Determine whether the sum of the first two digits is equal to the sum of its last two digits.\n"

			"24. Given a four-digit number. Determine whether the product of its numbers is a multiple of four.\n"

			"25. Given a natural number. Is it true that it ends in an odd digit?\n"

			"26. Given a natural number. Is it true that it ends with an even digit?\n"

			"27. Given a real number. Is it true that its integer part ends with an even digit?\n"

			"28. Given a real number. Is it true that its integer part is a multiple of three?\n"

			"29.Three real numbers are given. Square those of them whose values ​​are non-negative, and to the fourth power - negative.\n"

			"30. Two points are given: A (x1, y1) and B (x2, y2). Create an algorithm to determine which of the points is closer to the origin.\n"

			"31. Real numbers x and y are not equal to each other. Replace the smaller of these two numbers with half of their sum, and the larger with their double product.\n"

			"32. On the X0Y plane, point A is specified by its coordinates. Specify where it is located (on which axis or in which quadrant).\n"

			"33. Given the integers n, m. If the numbers are not equal, then replace each of them with the value of their sum, and if they are equal, then replace the numbers with zeros.\n"

			"34. Count the number of negative numbers among a, b, c.\n"

			"35. Count the number of positive numbers among a, b, c.\n"

			"36. Count the number of even numbers among a, b, c. The conditional operator does not use.\n"

			"37. Count the number of odd numbers among a, b, c. The conditional operator does not use.\n"

			"38. Three numbers are given, a, b, c. Are there exactly two even numbers among them?\n"

			"39. Three numbers are given, a, b, c. Are there exactly two odd numbers among them?\n"

			"40. Redistribute the values ​​of variables A and B so that A has a greater value, and B has a smaller one.\n"

			"41. Determine the correctness of the date entered from the keyboard (the number - from 1 to 31, a month - from 1 to 12). When forming the answer, it is necessary to take into account the actual number of days in the month. For February, take into account the number of days in a leap year.\n"

			"42. For the entered value of the date, count the number of days that have passed since the beginning of the epoch (January 1, 1970).\n"

			"43. For the entered date value, determine the number of the quarter to which this date belongs and the number of days elapsed since the beginning of this quarter.\n"

			"44. For the entered time value (HH - hour, MM - minutes, SS - seconds), determine the number of full minutes and the number of seconds that have passed first days. Also determine the number of full minutes past the beginning of a quarter of an hour, which corresponds to the specified point in time.\n"

			"45. Write a program that analyzes data on age and refers a person to one of four age groups: preschooler, student, employee, retired person. The age value is entered from the keyboard.\n"

			"46. ​​Create a program that determines whether the graph will function y = Ax2 + Bx + C through a given point with the coordinates (M, N).\n"

			"47. The values ​​of the lengths of the sides of the brick A, B, C are given. Determine whether it is possible to move a brick of a specified size through a hole of rectangular cross section with the sides D and E.\n"

			"48. Three positive numbers A, B and C are given. Determine whether they are consistently standing elements of an arithmetic or geometric progression.\n"

			"49. From the keyboard, enter the lengths of segments A, B, C and D. Determine them on the possibility of constructing triangles.\n"

			"50. Three points are given: A (x1, y1), B (x2, y2), C (x3, y3). Determine whether they are located on the same line. If not, calculate the angle B\n"
		);
	}

		int select = 0;

		int stop = 0;

		while (1) {

			printf("\n Task number = ");
			stop = scanf("%d", &select);
			fflush(stdin);
			if (stop == 1) {
				if ((select > 50) && (select < 1)) {
					puts("Try again. 0 or 1 <= Task number  <= 50");
				}
				else {
					break;
				}
			}
		}
		//*****************
		//case
		if (select == 0) {
			break;
		}

		if (select == 1) {
			task1();
		}

		if (select == 2) {
			task2();
		}

		if (select == 3) {
			task3();
		}

		if (select == 4) {
			task4();
		}

		if (select == 5) {
			task5();
		}

		if (select == 6) {
			task6();
		}

		if (select == 7) {
			task7();
		}

		if (select == 8) {
			task8();
		}

		if (select == 9) {
			task9();
		}

		if (select == 10) {
			task10();
		}

		if (select == 11) {
			task11();
		}

		if (select == 12) {
			task12();
		}

		if (select == 13) {
			task13();
		}

		if (select == 14) {
			task14();
		}

		if (select == 15) {
			task15();
		}

		if (select == 16) {
			task16();
		}

		if (select == 17) {
			task17();
		}

		if (select == 18) {
			task18();
		}

		if (select == 19) {
			task19();
		}

		if (select == 20) {
			task20();
		}

		if (select == 21) {
			task21();
		}

		if (select == 22) {
			task22();
		}

		if (select == 23) {
			task23();
		}

		if (select == 24) {
			task24();
		}

		if (select == 25) {
			task25();
		}


		if (select == 26) {
			task26();
		}

		//*****************

	}

	return 0;
}
