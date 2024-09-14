#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
struct student
{
    char famil[20];
    char name[20], facult[20];
    int nomzach;
    float sredbal;
}stud[3];
void vivod(struct student vvv) {

    for (int i = 0; i < 3; i++)
    {
        printf("Cтудент %s %s \n", stud[i].famil, stud[i].name);
        printf("Факультет %s \n", stud[i].facult);
        printf("Номер зачетной книжки %d \n", stud[i].nomzach);
        printf("Средний балл %d \n", stud[i].sredbal);
        printf("--------------------------------------------------------------------------------------------\n");
    }

}
#pragma warning(disable: 4996)
struct student* sozdanie() {
    struct student* bakalavri = (struct student*)malloc(3 * sizeof(struct student));
   
        for (int i = 0; i < 3; i++) {
            printf("Введите фамилию студента %d\n", i + 1);
            scanf("%s", stud[i].famil);
            rewind(stdin);
            printf("Введите имя студента %d\n", i + 1);
            scanf("%s", stud[i].name);
            rewind(stdin);
            printf("Введите факультет студента %d\n", i + 1);
            scanf("%s", stud[i].facult);
            rewind(stdin);
            printf("Введите номер зачётки студента %d\n", i + 1);
            scanf("%d", &stud[i].nomzach);
            rewind(stdin);
            printf("Введите средний балл зачётки студента %d\n", i + 1);
            scanf("%d", &stud[i].sredbal);
            rewind(stdin);
        }
    return bakalavri;
};

int poisk(struct student* src) {
    char name[20], famil[20], facult[20];
    unsigned int nomzach;
    float sredbal;
    int n,k=0;
    printf("Выберите критерий поиска:\n 1: Фамилия\n 2: Имя\n 3: Факультет\n 4: Номер зачетной книжки\n 5: средний балл\n");
    scanf("%d", &n);
    switch (n) {
    case 1:
        printf("Введите фамилию студента\n");
        scanf("%20s", famil);
        printf("Студенты, подходящте под заданные данные:\n");
        for (int i = 0; i < 3; i++) {
            if (strcmp(stud[i].famil,famil) == 0) {
                printf("%s %s %s %d %d\n", stud[i].famil, stud[i].name, stud[i].facult, stud[i].nomzach, stud[i].sredbal);
                k++;
            }
        }
        if (k == 0) {
            printf("Ни одного студента не найдено\n");
        }
        break;
    case 2:
        printf("Введите имя студента\n");
        scanf("%20s", name);
        printf("Студенты, подходящте под заданные данные:\n");
        for (int i = 0; i < 3; i++) {
            if (strcmp(stud[i].name, name) == 0) {
                printf("%s %s %s %d %d\n", stud[i].famil, stud[i].name, stud[i].facult, stud[i].nomzach, stud[i].sredbal);
                k++;
            }
        }
        if (k == 0) {
            ("Ни одного студента не найдено\n");
        }

        break;
    case 3:
        printf("Введите факультет студента\n");
        scanf("%20s", facult);
        printf("Студенты, подходящте под заданные данные:\n");
        for (int i = 0; i < 3; i++) {
            if (strcmp(stud[i].facult,facult) == 0) {
                printf("%s %s %s %d %d\n", stud[i].famil, stud[i].name, stud[i].facult, stud[i].nomzach, stud[i].sredbal);
                k++;
            }
        }
        if (k == 0) {
            printf("Ни одного студента не найдено\n");
        }
        break;
    case 4:
        printf("Введите номер зачетки студента\n");
        scanf("%d", &nomzach);
        printf("Студенты, подходящте под заданные данные:\n");
        for (int i = 0; i < 3; i++) {
            if (stud[i].nomzach == nomzach) {
                printf("%s %s %s %d %d\n", stud[i].famil, stud[i].name, stud[i].facult, stud[i].nomzach, stud[i].sredbal);
                k++;
            }
        }
        if (k == 0) {
            printf("Ни одного студента не найдено\n");
        }
        break;
    case 5:
        printf("Введите номер зачетки студента\n");
        scanf("%d", &sredbal);
        printf("Студенты, подходящте под заданные данные:\n");
        for (int i = 0; i < 3; i++) {
            if (stud[i].sredbal == sredbal) {
                printf("%s %s %s %d %d\n", stud[i].famil, stud[i].name, stud[i].facult, stud[i].nomzach, stud[i].sredbal);
                k++;
            }
        }
        if (k == 0) {
            printf("Ни одного студента не найдено\n");
        }
        break;
    default:
        printf("Ошибка, выберите один из представленых пунктов");
        break;
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    struct student* studd = sozdanie();
    printf("-----------------------\n");
    printf("--------------------------------\n");
    printf("------------------------------------------\n");
    printf("--------------------------------------------------\n");
  
        vivod(studd[3]);
    
    poisk(studd);
    free(studd);
    return 0;


}
