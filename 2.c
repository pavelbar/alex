#include <stdio.h>
#include <windows.h>

/*
 * Является ли число А делителем Б
 */

void myCls() {
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
            if ((nameVariable == 'A') && (answer == 0)) {
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

void isDivider(int A, int B) {       //Task 2
    if (B % A == 0) {
        puts("\n\nAll right. A is divider for B");
    } else {
        puts("\n\nError. A is NOT divider for B");
    }
}

int main() {
    while (1) {
        myCls();
        int B = 0;
        printf("Enter dividend B (int)\n\n");//делимое
        printf("Press ENTER to input mode");
        getchar();
        B = correctly('B');

        myCls();
        int A = 0;
        printf("Enter divider A (int)\n\n");//делитель
        printf("Press ENTER to input mode");
        getchar();
        A = correctly('A');

        myCls();
        printf("A = %d\nB = %d \n B / A", A, B);

        isDivider(A, B);

        printf("\nJob done. Press ENTER");
        getchar();
    }
    return 0;
}
