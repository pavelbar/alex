#include <stdio.h>
#include <windows.h>

/*
 * Дано натуральное число. Верно ли, что оно заканчивается нечетной цифрой?
 */

int correctly(char nameVariable) {
    system("cls");
    printf("MODE: Input INT Variable %c\n\n%c = ", nameVariable, nameVariable);
    int flag = 0;
    int answer = 0;

    while (1) {
        flag = scanf("%d", &answer);
        fflush(stdin);
        if ((flag == 1) && (answer > 0)) {
            printf("Variable %c correctly! \n\n", nameVariable);
            break;

        } else {
            printf("Variable %c not correctly! Try again. \n%c = ", nameVariable, nameVariable);
        }
    }
    printf("Press ENTER to normal mode");
    getchar();
    system("cls");
    return answer;
}


void naturalNumberIsOdd(int number) {       //Task25
    int digit = number % 10;

    printf("\n Last digit = %d\n", digit);

    if (digit % 2 != 0) {
        puts(" All right. Natural Number Is Odd");
    } else {
        puts(" Error. Natural Number Is NOT Odd");
    }
}


int main() {
    while (1) {
        int number = 0;
        printf("Enter natural number (int>0)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        number = correctly('A');

        system("cls");
        printf("Natural number = %d\n", number);

        naturalNumberIsOdd(number);

        printf("\nJob done. Press ENTER");
        getchar();
        system("cls");
    }
    return 0;
}
