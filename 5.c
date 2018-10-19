#include <stdio.h>
#include <windows.h>

/*
 * Дано целое число. Определить оканчивается ли оно четной цифрой (составное условие не использовать).
 */

void myCls() {
    system("cls");
    puts("************************************************************\n"
         "* Nizhniy Novgorod Technical University                    *\n"
         "* Study work number 2. Task number 5.                      *\n"
         "* Performed student 18 - IVT - 2. Kornilov Alexey          *\n"
         "************************************************************\n");
}

int correctly(char nameVariable) {
    myCls();
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
    return answer;
}

int isEven(int number) {
    return number % 2 == 0 ? 1 : 0;
}


int getLastDigit(int number) {
    return number % 10;
}

void solution(int number) {       //Task 5
    if (isEven(getLastDigit(number))) {
        puts(" All right. Last from A is Even");
    } else {
        puts(" Error. Last from A is NOT Even");
    }
}


int main() {
    while (1) {
        myCls();
        int A = 0;
        printf("Enter digit A (int)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        A = correctly('A');

        myCls();
        printf("A = %d\n", A);

        solution(A);

        printf("\nJob done. Press ENTER");
        getchar();
    }
    return 0;
}
