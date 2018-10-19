#include <stdio.h>
#include <windows.h>

/*
 * Если целое число М делится нацело на целое N, то вывести на экран частное от деления,
 * в противном случае вывести сообщение «M на N не делится без остатка».
 */

void myCls(int task) {
    system("cls");
    printf("************************************************************\n"
           "* Nizhniy Novgorod Technical University                    *\n");
    printf("* Study work number 2. Task number %d.                      *\n", task);
    printf("* Performed student 18 - IVT - 2. Kornilov Alexey          *\n"
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
    //case
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
    printf("    (INT variable, len =  %d | limit = %d)\n\n", len, lim);
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
        } else {
            printf("Variable %c not correctly! Check type (INT variable). Try again. \n%c = ", nameVariable, len,
                   nameVariable);
        }
    }

    sleep();
    return answer;
}

//###############################################################
//###############################################################
//###############################################################

int isEven(int number) {
    return number % 2 == 0 ? 1 : 0;
}


int getLastDigit(int number) {
    return number % 10;
}

//###############################################################
//###############################################################
//###############################################################

void solution1(int N, int M) {     //Task 1
    if (M % N == 0) {
        printf("%d\n", M / N);
    } else {
        puts("Error. Not null\n");
    }
}

void task1() {
    int task = 1;
    myCls(task);
    int M = 0;
    printf("--> Enter dividend M\n\n");//делимое
    M = correctly('M', 0, 0);

    myCls(task);
    int N = 0;
    printf("--> Enter divider N\n\n");//делитель
    N = correctly('N', 0, 5);

    myCls(task);
    printf("N = %d\nM = %d \n M / N = ", M, N);

    solution1(N, M);

    puts("\nJob done.");
    sleep();
}

void solution2(int A, int B) {       //Task 2
    if (B % A == 0) {
        puts("\n\nAll right. A is divider for B");
    } else {
        puts("\n\nError. A is NOT divider for B");
    }
}

//

void task2() {
    int task = 2;
    myCls(task);
    int B = 0;
    printf("Enter dividend B (int)\n\n");//делимое
    B = correctly('B', 0, 0);

    myCls(task);
    int A = 0;
    printf("Enter divider A (int)\n\n");//делитель
    A = correctly('A', 0, 5);

    myCls(task);
    printf("A = %d\nB = %d \n B / A", A, B);

    solution2(A, B);

    puts("\nJob done.");
    sleep();
}

//

void solution3(int number) {     //Task 3
    isEven(number) ? puts(" All right. A is Even") : puts(" Error. A is NOT Even");

    getLastDigit(number) == 4 ? puts(" All right. Lost is 4") : puts(" Error. A is NOT 4");
}

void task3() {
    int task = 3;
    myCls(task);
    int A = 0;
    printf("Enter digit A (int)\n\n");
    A = correctly('A', 0, 0);

    myCls(task);
    printf("A = %d\n", A);

    solution3(A);

    puts("\nJob done.");
    sleep();
}

//###############################################################
//###############################################################
//###############################################################

int main() {
    while (1) {
        myCls(0);
        puts("\n Select task.\n Task number 1 - Task number 50\n Input 0 for exit");
        int select = 0;

        int stop = 0;

        while (1) {
            printf("\n Task number = ");
            stop = scanf("%d", &select);
            fflush(stdin);
            if (stop == 1) {
                if ((select > 50) && (select < 1)) {
                    puts("Try again. 0 or 1 <= Task number  <= 50");
                } else {
                    break;
                }
            }
        }
        //*****************
        //case
        if (select == 0) {
            break;
        }

        if (select == 1) {
            task1();
        }

        if (select == 2) {
            task2();
        }

        if (select == 3) {
            task3();
        }
        //*****************

    }
    return 0;
}
