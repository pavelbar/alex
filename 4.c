#include <stdio.h>
#include <windows.h>

/*
 * Дано целое число. Определить является ли оно НЕчетным и оканчивается ли оно цифрой 7.
 */

int correctly(char nameVariable) {
    system("cls");
    printf("MODE: Input INT Variable %c\n\n%c = ", nameVariable, nameVariable);
    int flag = 0;
    int answer = 0;

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


void oddOrEndSeven(int A) {     //Task 4
    if (A % 2 == 1) {
        puts(" All right. A is NOT Even");
    } else {
        puts(" Error. A is Even");
    }

    if (A % 10 == 7) {
        puts(" All right. Lost is 7");
    } else {
        puts(" Error. Lost is NOT 7");
    }
}


int main() {
    while (1) {
        int A = 0;

        printf("Enter digit A (int)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        A = correctly('A');

        system("cls");
        printf("A = %d\n", A);

        oddOrEndSeven(A);

        printf("\nJob done. Press ENTER");
        getchar();
        system("cls");
    }
    return 0;
}
