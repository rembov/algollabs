#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct node {
    char inf[256];      
    int priority;       
    struct node* next;  
};

struct node* head = NULL;  // указатель на первый элемент списка

void spstore(void), review(void), del(char* name);

struct node* get_struct(void);  // функция создания элемента

// Функция создания элемента с приоритетом
struct node* get_struct(void) {
    struct node* p = NULL;
    char s[256];
    int pr;

    if ((p = (struct node*)malloc(sizeof(struct node))) == NULL) {  // выделяем память под новый элемент списка
        printf("Ошибка при распределении памяти\n");
        exit(1);
    }

    printf("Введите название объекта: \n");   // вводим данные
    scanf_s("%s", s, (unsigned)_countof(s));
    if (*s == 0) {
        printf("Запись не была произведена\n");
        return NULL;
    }

    printf("Введите приоритет объекта: \n");  // вводим приоритет
    scanf_s("%d", &pr);

    strcpy_s(p->inf, s);
    p->priority = pr;
    p->next = NULL;

    return p;  // возвращаем указатель на созданный элемент
}

// Вставка элемента в список с учетом приоритета 
void spstore(void) {
    struct node* p = get_struct();
    if (p == NULL) return;

    if (head == NULL || p->priority > head->priority) {  // вставка перед головой списка
        p->next = head;
        head = p;
    }
    else {
        struct node* current = head;
        // Ищем место для вставки
        while (current->next != NULL && current->next->priority >= p->priority) {
            current = current->next;
        }
        p->next = current->next;
        current->next = p;
    }
}

// Просмотр содержимого списка 
void review(void) {
    struct node* struc = head;
    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }
    while (struc) {
        printf("Имя: %s, Приоритет: %d\n", struc->inf, struc->priority);
        struc = struc->next;
    }
}
struct node* find(char* name)
{
    struct node* struc = head;
    if (head == NULL)
    {
        printf("Список пуст\n");
    }
    while (struc)
    {
        if (strcmp(name, struc->inf) == 0)
        {
            printf("Элемент  найден!\n");
            printf("Элемент: %s\n", struc->inf);
            return struc;
        }
        struc = struc->next;

    }
    printf("Элемент не найден\n");
    return NULL;

}
// Удаление элемента по содержимому 
// Удаление всех элементов по содержимому
void del(char* name) {
    struct node* struc = head;
    struct node* prev = NULL;
    int found = 0;

    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }

    // Проход по списку для поиска и удаления всех совпадающих элементов
    while (struc) {
        if (strcmp(name, struc->inf) == 0) {
            found = 1;  // Элемент найден

            // Удаление первого элемента
            if (prev == NULL) {
                head = struc->next;
                free(struc);
                struc = head;  // обновляем текущий узел после удаления головы
            }
            else {  // Удаление элемента не в начале списка
                prev->next = struc->next;
                free(struc);
                struc = prev->next;  // обновляем текущий узел
            }

            printf("Элемент удален\n");
        }
        else {
            prev = struc;  // Обновляем предыдущий элемент
            struc = struc->next;  // Переходим к следующему элементу
        }
    }

    if (!found) {
        printf("Элемент не найден\n");
    }
}



int main() {
    setlocale(LC_ALL, "");

    int choice;
    char name[256];

    do {
        printf("\nМеню:\n");
        printf("1. Добавить элемент\n");
        printf("2. Просмотреть список\n");
        printf("3. Удалить элемент\n");
        printf("4. Поиск элемента\n");
        printf("5. Выход\n");
        printf("Введите выбор: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            spstore();
            break;
        case 2:
            
                review();
                break;
           
        case 3:
            printf("Введите название объекта для удаления: ");
            scanf_s("%s", name, (unsigned)_countof(name));
            del(name);
            break;
        case 4:
            printf("Введите элемент для поиска: ");
            scanf_s("%s", name, (unsigned)_countof(name));
            *find(name);
            break;

        case 5:
            printf("Выход...\n");
            break;
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}
