#include <stdio.h>
#include <windows.h>

/*
/*Дано трехзначное число. Определить, есть ли среди его цифр одинаковые.
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


void haveEqual(int num) { //Task 22
    int rightDigit = abs(num) % 10;
    int leftDigit = abs(num) / 100;
    int centerDigit = abs(num) / 10 % 10;

    printf(" Left Digit =%d\n", leftDigit);
    printf(" Right Digit =%d\n", rightDigit);
    printf(" Center Digit =%d\n", centerDigit);

    if ((leftDigit == centerDigit) || (leftDigit == rightDigit) || (centerDigit == rightDigit)) {
        puts(" All right. Have equal");
    } else {
        puts(" Error. Have NOT equal");
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

        haveEqual(num);

        printf("\nJob done. Press ENTER");
        getchar();
        system("cls");
    }
    return 0;
}
