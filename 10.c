#define PI_VAL 3.14

#include <stdio.h>
#include <windows.h>
#include <math.h>

/*
 * Известные площади круга и квадрата. Определить уместится ли круг в квадрате
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


void canCircleToSquare(int areaCircle, int areaSquare) {      //Task 10
    double radiusCircle = sqrt(areaCircle / PI_VAL);
    double diametrCircle = radiusCircle * 2;
    double lenghtSquare = sqrt(areaSquare);

    printf("\n radius Circle = %f", radiusCircle);
    printf("\n diametr Circle = %f", diametrCircle);
    printf("\n length Square = %f", lenghtSquare);

    if (diametrCircle <= lenghtSquare) {
        puts("\n\n All right. Circle in Square");
    } else {
        puts("\n\n Error. Lite Square and big Circle");
    }
}


int main() {
    while (1) {
        double areaCircle = 0;
        printf("Enter area for circle (int > 0)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        areaCircle = correctly('A');
        
        double areaSquare = 0;
        printf("Enter area for square (int > 0)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        areaSquare = correctly('B');

        system("cls");
        printf("Area for circle = %f\nArea for square = %f\n", areaCircle, areaSquare);

        canCircleToSquare(areaCircle, areaSquare);

        printf("\nJob done. Press ENTER");
        getchar();
        system("cls");
    }
    return 0;
}