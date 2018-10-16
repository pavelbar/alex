
#include <stdio.h>
#include <conio.h>
#include <windows.h>


/*
 * Если целое число М делится нацело на целое N, то вывести на экран частное от деления,
 * в противном случае вывести сообщение «M на N не делится без остатка».
 */


int correctly(char nameVariable) {
    system("cls");
    printf("MODE: Input Variable %c\n\n%c = ", nameVariable, nameVariable);
    int flag = 0;
    int answer;

    while (flag != 1) {
        flag = scanf("%d", &answer);
        fflush(stdin);
        if (flag == 1) {
            printf("Variable %c correctly! \n\n", nameVariable);
        } else {
            printf("Variable %c not correctly! Try again. \n%c = ", nameVariable, nameVariable);
        }
    }
    printf("Press ENTER to normal mode");
    getchar();
    system("cls");
    return answer;
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
        printf("N = %d\nM = %d \n", M, N);
        printf("M / N = ");
        if (M % N == 0) {
            printf("%d\n", M / N);
        } else {
            printf("Error. Not null\n");
        }

        printf("\nJob done. Press ENTER");
        getchar();
        system("cls");
    }
    return 0;
}
