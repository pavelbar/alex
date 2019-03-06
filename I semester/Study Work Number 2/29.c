#include <stdio.h>
#include <windows.h>

/*
 * Даны три вещественные числа. Возвести в квадрат те из них, значения которых неотрицательные, и в четвертую степень – отрицательные.
 */

void correctly(char nameVariable, float *number) {
    system("cls");
    printf("MODE: Input FLOAT Variable %c\n\n%c = ", nameVariable, nameVariable);
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


void solution(float numberOne, float numberTwo, float numberThree) {       //Task29
    if (numberOne >= 0) {
        numberOne = numberOne * numberOne;
    } else {
        numberOne = numberOne * numberOne * numberOne * numberOne;
    }

    if (numberTwo >= 0) {
        numberTwo = numberTwo * numberTwo;
    } else {
        numberTwo = numberTwo * numberTwo * numberTwo * numberTwo;
    }

    if (numberThree >= 0) {
        numberThree = numberThree * numberThree;
    } else {
        numberThree = numberThree * numberThree * numberThree * numberThree;
    }

    printf("\n result number one = %f\n", numberOne);
    printf("\n result number two = %f\n", numberTwo);
    printf("\n result number three = %f\n", numberThree);
}


int main() {
    while (1) {
        float numberOne = 0;
        printf("Enter double number (float)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        correctly('A', &numberOne);

        float numberTwo = 0;
        printf("Enter double number (float)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        correctly('B', &numberTwo);

        float numberThree = 0;
        printf("Enter double number (float)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        correctly('C', &numberThree);

        system("cls");
        printf("Natural number one = %f\n", numberOne);
        printf("Natural number two = %f\n", numberTwo);
        printf("Natural number three = %f\n", numberThree);

        solution(numberOne, numberTwo, numberThree);

        printf("\nJob done. Press ENTER");
        getchar();
        system("cls");
    }
    return 0;
}
