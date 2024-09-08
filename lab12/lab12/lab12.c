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
        printf("Средний балл %d \n", stud[i].nomzach);
    }

}
struct student* sozdanie() {
    struct student* bakalavri = (struct student*)malloc(3 * sizeof(struct student));
    for (int i = 0; i < 3; i++) {
        printf("Введите фамилию : ");
        scanf_s("%20s", stud[i].famil);
        printf("Введите имя : ");
        scanf_s("%20s", stud[i].name);
        printf("Введите факультет : ");
        scanf_s("%20s", stud[i].facult);
        printf("Введите номер зачётки : ");
        scanf_s("%u", &stud[i].nomzach);
        printf("Введите средний балл : ");
        scanf_s("%f", &stud[i].sredbal);
    }
    return bakalavri;
};

int poisk(struct student* src, int stud_num) {
    char name[20], famil[20], facult[20];
    unsigned int nomzach;
    int sredbal;
    printf("Введите фамилию : ");
    scanf_s("%s", famil);
    printf("Введите имя : ");
    scanf_s("%s", name);
    printf("Введите факультет : ");
    scanf_s("%s", facult);
    printf("Введите номер зачётки : ");
    scanf_s("%u", &nomzach);
    printf("Введите средний балл : ");
    scanf_s("%u", &sredbal);

    for (int i = 0; i < 3; i++) {
        if (strcmp(famil, stud[i].famil) == 0 && strcmp(name, stud[i].name) == 0 &&
            strcmp(facult, stud[i].facult) == 0 && nomzach == stud[i].nomzach
            ) {
            printf("Студент найден:");
            vivod(stud[i]);
            return 0;
        }
    }
    printf("Такого студента не существует");
    return 0;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    struct student* studd = sozdanie();
    for (int i = 0; i < 3; i++) {
        vivod(studd[i]);
    }
    poisk(studd, 3);
    free(studd);
    return 0;


}
