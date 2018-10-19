#include <stdio.h>
#include <windows.h>
#include <math.h>

/*
 * Дано двузначное число. Определить, кратна ли трем сумма его цифр.
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
            if (getLengthNumber(answer) == 2) {
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


void solution(int num) { //Task 15
    int rightDigit = getLastDigit(num);
    int leftDigit = getFirstDigit(num);
    int sum = rightDigit + leftDigit;


    printf(" Left Digit =%d\n", leftDigit);
    printf(" Right Digit =%d\n", rightDigit);
    printf(" Sum left and right digit =%d\n", sum);

    if (sum % 3 == 0) {
        puts(" All right. Sum is multiple of three");
    } else {
        puts(" Error. Sum is NOT multiple of three");
    }
}


int main() {
    while (1) {
        int num = 0;
        printf("Enter digit (int, length = 2)\n\n");
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
