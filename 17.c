#include <stdio.h>
#include <windows.h>
#include <math.h>

/*
/*Дано трехзначное число. Определить, равен ли квадрат этого числа сумме кубов его цифр.
 */

int getLengthNumber(int numb) {
    int count = 0;
    while (numb) {
        numb /= 10;
        count++;
    }
    return count;
}


int correctly(char nameVariable) {
    system("cls");
    printf("MODE: Input INT Variable %c\n\n%c = ", nameVariable, nameVariable);
    int flag = 0;
    int answer = 0;

    while (1) {
        flag = scanf("%d", &answer);
        fflush(stdin);
        if (flag == 1) {
            if (getLengthNumber(answer) == 3) {
                printf("Variable %c correctly! \n\n", nameVariable);
                break;
            } else {
                printf("Variable %c not correctly! Try again. \n%c = ", nameVariable, nameVariable);
            }

        } else {
            printf("Variable %c not correctly! Try again. \n%c = ", nameVariable, nameVariable);
        }
    }
    printf("Press ENTER to normal mode");
    getchar();
    system("cls");
    return answer;
}

int getLastDigit(int number) {
    return abs(number % 10);
}

int getFirstDigit(int number) {
    return number / pow(10, getLengthNumber(number) - 1);
}

int getDigitInPos(int number, int pos) {//0,1,2....
    number = abs(number);
    int shift = number / pow(10, getLengthNumber(number) - 1 - pos);
    return shift % 10;
}

void solution(int num) { //Task 17
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
    } else {
        puts(" Error. Sum and square is not equal");
    }
}


int main() {
    while (1) {
        int num = 0;
        printf("Enter digit (int, length = 3)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        num = correctly('A');

        system("cls");
        printf("digit = %d\n", num);

        solution(num);

        printf("\nJob done. Press ENTER");
        getchar();
        system("cls");
    }
    return 0;
}
