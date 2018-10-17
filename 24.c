#include <stdio.h>
#include <windows.h>

/*
/*Дано четырехзначное число. Определить, кратно ли четырем произведение его цифр.
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
            if (getLengthNumber(answer) == 4) {
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


void isMultipleOfFour(int num) { //Task 24
    int rightDigit = abs(num) % 10;
    int leftDigit = abs(num) / 1000;
    int centerRightDigit = abs(num) / 10 % 10;
    int centerLeftDigit = abs(num) / 100 % 10;

    int mult = rightDigit * leftDigit * centerRightDigit * centerLeftDigit;

    printf(" Left Digit =%d\n", leftDigit);
    printf(" Center Left Digit =%d\n", centerLeftDigit);
    printf(" Center Right Digit =%d\n", centerRightDigit);
    printf(" Right Digit =%d\n", rightDigit);

    printf(" Multiple =%d\n", mult);

    if (mult % 4 == 0) {
        puts(" All right. Humber is Multiple Of Four");
    } else {
        puts(" Error. Humber is NOT Multiple Of Four");
    }
}


int main() {
    while (1) {
        int num = 0;
        printf("Enter digit (int, length = 4)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        num = correctly('A');

        system("cls");
        printf("digit = %d\n", num);

        isMultipleOfFour(num);

        printf("\nJob done. Press ENTER");
        getchar();
        system("cls");
    }
    return 0;
}
