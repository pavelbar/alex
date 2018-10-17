#include <stdio.h>
#include <windows.h>

/*
 * Известны год и месяц рождения человека, а также год и номер месяца сегодняшнего дня. Определить возраст человека,
 * число полных лет. В случае совпадения указанных месяцев считать, что прошел полный год.
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


void solution(int yearBirth, int monthBirth, int yearNow, int monthNow) {       //Task6
    int age = yearNow - yearBirth;
    if (monthNow < monthBirth) {
        age--;
    }

    printf("\n Age = %d\n", age);
}


int main() {
    while (1) {
        int yearBirth = 0;
        printf("Enter year of birth (int>0)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        yearBirth = correctly('A');

        int monthBirth = 0;
        printf("Enter month of birth (int>=0)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        monthBirth = correctly('B');

        int yearNow = 0;
        printf("Enter year now (int>=0)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        yearNow = correctly('B');

        int monthNow = 0;
        printf("Enter month now (int>=0)\n\n");
        printf("Press ENTER to input mode");
        getchar();
        monthNow = correctly('D');

        system("cls");
        printf("yearBirth = %d\nmonthBirth = %d\nyearNow = %d\nmonthNow = %d", yearBirth, monthBirth, yearNow,
               monthNow);

        solution(yearBirth, monthBirth, yearNow, monthNow);

        printf("\nJob done. Press ENTER");
        getchar();
        system("cls");
    }
    return 0;
}
