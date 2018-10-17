#include <stdio.h>
#include <windows.h>

/*
 * Дано двузначное число. Определить, является ли сумма его цифр двузначным числом
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


void isTwoDigitNumber(int num) { //Task 14
    int rightDigit = abs(num) % 10;
    int leftDigit = abs(num) / 10;
    int sum = rightDigit + leftDigit;


    printf(" Left Digit =%d\n", leftDigit);
    printf(" Right Digit =%d\n", rightDigit);
    printf(" Sum left and right digit =%d\n", sum);

    if (getLengthNumber(sum) == 2) {
        puts(" All right. Sum is two-digit number");
    } else {
        puts(" Error. Sum is NOT two-digit number");
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

        isTwoDigitNumber(num);

        printf("\nJob done. Press ENTER");
        getchar();
        system("cls");
    }
    return 0;
}