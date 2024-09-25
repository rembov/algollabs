#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
struct node
{
	char inf[256];  // полезная информация
	int priority;
	struct node* next; // ссылка на следующий элемент 
};


int size = 0;
struct node* head = NULL, * last = NULL, * f = NULL; // указатели на первый и последний элементы списка
int dlinna = 0;
void spstore(), review(void), del(char* name);

char find_el[256];
struct node* find(char* name); // функция нахождения элемента
struct node* get_struct(void); // функция создания элемента

void spstore(void)
{

	struct node* p = NULL;
	p = get_struct();
	if (head == NULL && p != NULL)	// если списка нет, то устанавливаем голову списка
	{
		head = p;
		last = p;
	}
	else {
		struct node* struc = head;
		struct node* prev = NULL;
		while (struc)
		{
			if (struc != NULL && p != NULL) // список уже есть, то вставляем в конец
			{
				if (p->priority > struc->priority) {
					if (prev != NULL)
						prev->next = p;
					if (head == struc)
						head = p;
					p->next = struc;
					return;
				}
				else {
					prev = struc;
					struc = struc->next;


				}
			}

		}
		prev->next = p;
		p->next = NULL;


	}
	return;
}

struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	printf("Введите название объекта: \n");   // вводим данные
	scanf("%s", s);
	printf("Введите приоритет объекта: \n");
	scanf("%d", &p->priority);
	if (*s == 0)
	{
		printf("Запись не была произведена\n");
		return NULL;
	}
	strcpy(p->inf, s);

	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

/* Последовательное добавление в список элемента (в конец)*/

/* Просмотр содержимого списка. */
void review(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	while (struc)
	{
		printf("Имя - %s, \n", struc->inf);

		struc = struc->next;
	}
	return;
}




/* Поиск элемента по содержимому. */
struct node* find()
{
	char name[20];
	scanf("%s", name);
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
			return struc;
		}
		struc = struc->next;
	}
	printf("Элемент не найден\n");
	return NULL;
}

/* Удаление элемента по содержимому. */
void del()
{
	char name[20];
	scanf("%s", name);
	struct node* struc = head; // указатель, проходящий по списку установлен на начало списка
	struct node* prev = nullptr;// указатель на предшествующий удаляемому элемент
	int flag = 0;      // индикатор отсутствия удаляемого элемента в списке

	if (head == NULL) // если голова списка равна NULL, то список пуст
	{
		printf("Список пуст\n");
		return;
	}

	if (strcmp(name, struc->inf) == 0) // если удаляемый элемент - первый
	{
		flag = 1;
		head = struc->next; // устанавливаем голову на следующий элемент
		free(struc);  // удаляем первый элемент
		struc = head; // устанавливаем указатель для продолжения поиска
	}
	else
	{
		prev = struc;
		struc = struc->next;
	}

	while (struc) // проход по списку и поиск удаляемого элемента
	{
		if (strcmp(name, struc->inf) == 0) // если нашли, то
		{
			flag = 1;         // выставляем индикатор
			if (struc->next)  // если найденный элемент не последний в списке
			{
				prev->next = struc->next; // меняем указатели
				free(struc);		    // удаляем  элемент
				struc = prev->next; // устанавливаем указатель для продолжения поиска
			}
			else			// если найденный элемент последний в списке
			{
				prev->next = NULL; // обнуляем указатель предшествующего элемента
				free(struc);	// удаляем  элемент
				return;
			}
			printf("Элемент удалён\n");
		}
		else	// если не нашли, то
		{
			prev = struc; // устанавливаем указатели для продолжения поиска
			struc = struc->next;
		}

	}

	if (flag == 0)				// если флаг = 0, значит нужный элемент не найден
	{
		printf("Элемент не найден\n");
		return;
	}
	return;

}
void remove() {
	struct node* struc = head; // указатель, проходящий по списку установлен на начало списка
	struct node* prev ;// указатель на предшествующий удаляемому элемент


	if (head->next != NULL) 			// если найденный элемент последний в списке
	{
		head = head->next; // обнуляем указатель предшествующего элемента
		free(struc);	// удаляем  элемент
		return;
	}
	else
	{
		head = NULL;
		free(struc);
	}
	return;

}
void reverse() {
	struct node* prev = NULL;
	struct node* current = head;
	struct node* next = NULL;

	while (current != NULL) {
		next = current->next; // сохраняем следующий элемент
		current->next = prev; // разворачиваем ссылку
		prev = current; // передвигаем указатели на один элемент вперед
		current = next;
	}
	head = prev; // устанавливаем новую голову
}


int main() {

	setlocale(LC_ALL, "Russian");
	int k = 1;
	node* Begin, * End;
	node* el = new node;
	el->next = NULL;
	Begin = End = el;
	while (k) {
		cout << "Меню:\n";
		cout << "1.Добавление элемента\n2.Удаление элемента по содержимому\n3.Поиск элемента по содержимому\n4.Вывод элементов на экран\n5.Удаление последнего элемента\n6.Инверсия очереди\n" << "0.Выход" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
			spstore();
			break;
		case 2:
			cout << "Введите элемент поиска: ";
			del();
			break;
		case 3:
			cout << "Введите элемент поиска: ";
			*find();
			break;
		case 4:
			review();
			break;
		case 5:
			remove();
			break;
		case 6:
			reverse();
			break;
		}
		
	}
	cout << endl;
	system("pause");
	return 0;
}
