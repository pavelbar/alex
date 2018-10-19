#include <stdio.h>
#include <windows.h>

/*
 * Является ли число А делителем Б
 */

void myCls() {
    system("cls");
    puts("************************************************************\n"
         "* Nizhniy Novgorod Technical University                    *\n"
         "* Study work number 2. Task number 2.                      *\n"
         "* Performed student 18 - IVT - 2. Kornilov Alexey          *\n"
         "************************************************************\n");
}

int getLengthNumber(int numb) {
    int count = 0;

    if (numb == 0) {
        return 1;
    }

    while (numb) {
        numb /= 10;
        count++;
    }
    return count;
}

int checkLen(int var, int len) {
    int res = 0;
    if (len == 0) {
        res = 1;
    } else if (getLengthNumber(var) == len) {
        res = 1;
    }
    return res;
}

int checkLimit(int var, int lim) {
    int res = 0;

    if (lim == 0) {
        res = 1;
    }
    if (lim == 1) {
        if (var > 0) {
            res = 1;
        }
    }
    if (lim == 2) {
        if (var >= 0) {
            res = 1;
        }
    }
    if (lim == 3) {
        if (var < 0) {
            res = 1;
        }
    }
    if (lim == 4) {
        if (var <= 0) {
            res = 1;
        }
    }
    if (lim == 5) {
        if (var != 0) {
            res = 1;
        }
    }
    return res;
}

void sleep() {
    printf(" _Press ENTER");
    getchar();
}

int correctly(char nameVariable, int len, int lim) {
    printf(" MODE: Input INT Variable %c\n\n", nameVariable);
    puts(" =============================\n"
         " ||           HELP          ||\n"
         " =============================\n"
         " || len - length            ||\n"
         " || ========================||\n"
         " || lim - limit             ||\n"
         " || 0: off (unlimit)        ||\n"
         " || 1: x >  0;              ||\n"
         " || 2: x >= 0;              ||\n"
         " || 3: x <  0;              ||\n"
         " || 4: x <= 0               ||\n"
         " || 5: x != 0               ||\n"
         " =============================");
    printf("    (len =  %d | limit = %d)\n\n", len, lim);
    printf("%c = ", nameVariable);

    int stop = 0;
    int answer = 0;

    while (1) {
        stop = scanf("%d", &answer);
        fflush(stdin);
        if (stop == 1) {
            if (checkLen(answer, len) == 1) {
                if (checkLimit(answer, lim) == 1) {
                    printf("\n Variable %c correctly! \n\n", nameVariable);
                    break;
                } else {
                    printf("Variable %c not correctly! Check restrict (limit != %d). Try again. \n%c = ", nameVariable,
                           lim, nameVariable);
                }
            } else {
                printf("Variable %c not correctly! Check length (length != %d). Try again. \n%c = ", nameVariable, len,
                       nameVariable);
            }
        }
    }

    sleep();
    return answer;
}

void solution2(int A, int B) {       //Task 2
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
        B = correctly('B', 0, 0);

        myCls();
        int A = 0;
        printf("Enter divider A (int)\n\n");//делитель
        A = correctly('A', 0, 5);

        myCls();
        printf("A = %d\nB = %d \n B / A", A, B);

        solution2(A, B);

        puts("Job done.");
        sleep();
    }
    return 0;
}
