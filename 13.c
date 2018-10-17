#include <stdio.h>
#include <windows.h>

/*
 * Дано двузначное число. Определить, равен ли квадрат этого числа учетверенной сумме кубов его цифр.
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


void solution(int num) { //Task 13
    int rightDigit = abs(num) % 10;
    int leftDigit = abs(num) / 10;
    int squaredNumber = num * num;
    int result = 4 * (leftDigit * leftDigit * leftDigit + rightDigit * rightDigit * rightDigit);

    printf(" Left Digit =%d\n", leftDigit);
    printf(" Right Digit =%d\n", rightDigit);
    printf(" squared Number =%d\n", squaredNumber);
    printf(" quadruple sum of cubes =%d\n", result);

    if (squaredNumber == result) {
        puts(" All right. Equal");
    } else {
        puts(" Error. NOT Equal");
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
