#define PI_VAL 3.14

#include <stdio.h>
#include <windows.h>

/*
 * Даны радиус круга и сторона квадрата. У какой фигуры площадь больще?
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


void compareArea(int radius, int length) {      //Task 9
    double sCircle = PI_VAL * radius * radius;
    double sSquare = length * length;

    printf("\n Area Circle = %f\n Area Square = %f\n", sCircle, sSquare);

    if (sCircle < sSquare) {
        puts(" Area Circle < Area Square");
    } else {
        puts(" Area Circle >= Area Square");
    }
}


int main() {
    while (1) {
        double radius = 0;

        printf("Enter radius for circle (int > 0)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        radius = correctly('A');

        double lenght = 0;
        printf("Enter lenght for square (int > 0)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        lenght = correctly('B');

        system("cls");
        printf("radius for circle = %f\nlenght for square = %f\n", radius, lenght);

        compareArea(radius, lenght);

        printf("\nJob done. Press ENTER");
        getchar();
        system("cls");
    }
    return 0;
}
