#include <stdio.h>
#include <windows.h>

/*
 * Дано трехзначное число. Выяснить, является ли оно палиндромом («перевертышем»),
 * то есть числом, десятичная запись которого читается одинаково слева направо и справа налево
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
    number = abs(number);
    int first = 0;
    while (number > 0) {
        first = number % 10;
        number = number / 10;
    }
    return first;
}

void isPalindrome(int num) { //Task 16
    int rightDigit = getLastDigit(num);
    int leftDigit = getFirstDigit(num);

    printf(" Left Digit =%d\n", leftDigit);
    printf(" Right Digit =%d\n", rightDigit);

    if (rightDigit == leftDigit) {
        puts(" All right. Digit is palindrome");
    } else {
        puts(" Error. Digit is NOT palindrome");
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

        isPalindrome(num);

        printf("\nJob done. Press ENTER");
        getchar();
        system("cls");
    }
    return 0;
}
