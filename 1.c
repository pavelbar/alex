#include <stdio.h>
#include <windows.h>

/*
 * Если целое число М делится нацело на целое N, то вывести на экран частное от деления,
 * в противном случае вывести сообщение «M на N не делится без остатка».
 */

void myCls(){
    system("cls");
    puts("************************************************************\n"
         "*Nizhniy Novgorod Technical University*\n*Study work number 2. Task number 1."
         "*\n *Performed student 18 - IVT - 2. Kornilov Alexey "
         "*\n************************************************************\n");
}

int correctly(char nameVariable) {
    myCls();
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
        myCls();
        int M = 0;
        printf("Enter dividend M (int)\n\n");//делимое
        printf("Press ENTER to input mode");
        getchar();
        M = correctly('M');

        myCls();
        int N = 0;
        printf("Enter divider N (int)\n\n");//делитель
        printf("Press ENTER to input mode");
        getchar();
        N = correctly('N');

        myCls();
        printf("N = %d\nM = %d \n M / N = ", M, N);

        divisionWithoutRemainder(N, M);

        printf("\nJob done. Press ENTER");
        getchar();
    }
    return 0;
}
