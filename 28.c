#include <stdio.h>
#include <windows.h>

/*
 * Дано вещественное число. Верно ли, что его целая часть кратна трем?
 */

void correctly(char nameVariable, float *number) {
    system("cls");
    printf("MODE: Input DOUBLE Variable %c\n\n%c = ", nameVariable, nameVariable);
    int flag = 0;
    float answer = 0;

    while (flag != 1) {
        flag = scanf("%f", &answer);
        fflush(stdin);
        if (flag == 1) {
            printf("Variable %c correctly! \n\n", nameVariable);
            *number = answer;
        } else {
            printf("Variable %c not correctly! Try again. \n%c = ", nameVariable, nameVariable);
        }
    }
    printf("Press ENTER to normal mode");
    getchar();
    system("cls");
}


void solution(float number) {       //Task28
    int wholePart = number;

    printf("\n Whole Part = %d\n", wholePart);

    if (wholePart % 3 == 0) {
        puts(" All right. Number is Multiple Of three");
    } else {
        puts(" Error. Number is NOT Multiple Of three");
    }
}


int main() {
    while (1) {
        float number = 0;
        printf("Enter double number (double)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        correctly('A', &number);

        system("cls");
        printf("Natural number = %f\n", number);

        solution(number);

        printf("\nJob done. Press ENTER");
        getchar();
        system("cls");
    }
    return 0;
}
