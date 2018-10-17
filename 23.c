#include <stdio.h>
#include <windows.h>

/*
/*Дано четырехзначное число. Определить, равна ли сумма двух первых его цифр сумме двух его последних цифр.
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


void isLeftSumEqualRightSum(int num) { //Task 23
    int rightDigit = abs(num) % 10;
    int leftDigit = abs(num) / 1000;
    int centerRightDigit = abs(num) / 10 % 10;
    int centerLeftDigit = abs(num) / 100 % 10;

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
    } else {
        puts(" Error. Left sum is NOT equal for Right sum");
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

        isLeftSumEqualRightSum(num);

        printf("\nJob done. Press ENTER");
        getchar();
        system("cls");
    }
    return 0;
}
