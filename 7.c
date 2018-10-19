#define FOOTS_IN_KILOMMETER 0.45

#include <stdio.h>
#include <windows.h>

/*
 * Известны два расстояниея. Одно в КМ другое в футах. (1км = 0.45 фута). Какое расстояние меньше?
 */

int correctly(char nameVariable) {
    system("cls");
    printf("MODE: Input INT Variable %c\n\n%c = ", nameVariable, nameVariable);
    int flag = 0;
    int answer = 0;

    while (1) {
        flag = scanf("%d", &answer);
        fflush(stdin);
        if ((flag == 1) && (answer > 0)) {
            printf("Variable %c correctly! \n\n", nameVariable);
            break;

        } else {
            printf("Variable %c not correctly! Try again. \n%c = ", nameVariable, nameVariable);
        }
    }
    printf("Press ENTER to normal mode");
    getchar();
    system("cls");
    return answer;
}


double footToKm(int distance) {
    return distance * FOOTS_IN_KILOMMETER;
}


void solution(int km, int foot) {       //Task7
    double footsToKm = footToKm(foot);

    printf("\n distance 2 (KM) = %f\n", footsToKm);

    if (km < footsToKm) {
        puts(" distance 1 < distance 2");
    } else {
        puts(" distance 1 >= distance 2");
    }
}


int main() {
    while (1) {
        double distanceOneKm = 0;
        printf("Enter distance 1 (Km) (int>0)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        distanceOneKm = correctly('A');

        double distanceTwoFoot = 0;
        printf("Enter distance 2 (Foot) (int>=0)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        distanceTwoFoot = correctly('B');

        system("cls");
        printf("distance 1 (KM) = %f\ndistance 2 (Foot) = %f\n", distanceOneKm, distanceTwoFoot);

        solution(distanceOneKm, distanceTwoFoot);

        printf("\nJob done. Press ENTER");
        getchar();
        system("cls");
    }
    return 0;
}
