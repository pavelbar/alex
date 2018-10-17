#define METERS_IN_KILOMMETER 1000

#include <stdio.h>
#include <windows.h>

/*
 * Известны две скорости. Одна в КМ/ч, другая в М/С. Какая скорость больше?
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


void compareSpeed(int kmH, int mS) {        //Task 8
    double speedTwoKm = mS / METERS_IN_KILOMMETER;

    printf("\n speed 2 (Km/H) = %f\n", speedTwoKm);

    if (labs(kmH) < labs(speedTwoKm)) {
        puts(" speed 1 < speed 2");
    } else {
        puts(" speed 1 >= speed 2");
    }
}


int main() {
    while (1) {
        double speedOneKmH = 0;
        printf("Enter speed 1 (Km/H) (int)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        speedOneKmH = correctly('A');

        double speedTwoMs = 0;
        printf("Enter speed 2 (M/s) (int)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        speedTwoMs = correctly('B');

        system("cls");
        printf("speed 1 (Km/H) = %f\nspeed 2 (M/s) = %f\n", speedOneKmH, speedTwoMs);

        compareSpeed(speedOneKmH, speedTwoMs);

        printf("\nJob done. Press ENTER");
        getchar();
        system("cls");
    }
    return 0;
}
