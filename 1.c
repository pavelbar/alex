#include <stdio.h>
#include <windows.h>

/*
 * Если целое число М делится нацело на целое N, то вывести на экран частное от деления,
 * в противном случае вывести сообщение «M на N не делится без остатка».
 */

int correctly(char nameVariable) {
    system("cls");
    printf("MODE: Input INT Variable %c\n\n%c = ", nameVariable, nameVariable);
    int flag = 0;
    int answer = 0;

    while (1) {
        flag = scanf("%d", &answer);
        fflush(stdin);
        if (flag == 1) {
            if ((nameVariable == 'N') && (answer == 0)) {
                printf("Variable %c not correctly! Try again. \n%c = ", nameVariable, nameVariable);
            } else {
                printf("Variable %c correctly! \n\n", nameVariable);
                break;
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


void divisionWithoutRemainder(int N, int M) {     //Task 1
    if (M % N == 0) {
        printf("%d\n", M / N);
    } else {
        puts("Error. Not null\n");
    }
}


int main() {
    while (1) {
        int M = 0;
        printf("Enter dividend M (int)\n\n");//делимое
        printf("Press ENTER to input mode");
        getchar();
        M = correctly('M');

        int N = 0;
        printf("Enter divider N (int)\n\n");//делитель
        printf("Press ENTER to input mode");
        getchar();
        N = correctly('N');

        system("cls");
        printf("N = %d\nM = %d \n M / N = ", M, N);

        divisionWithoutRemainder(N, M);

        printf("\nJob done. Press ENTER");
        getchar();
        system("cls");
    }
    return 0;
}
