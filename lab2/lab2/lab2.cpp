#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<locale.h>
#include<math.h>
int main(void)
{int i = 0, j = 0, r,m;
	int  elem_c;
	setlocale(LC_ALL, "");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	clock_t start, end; // объявляем переменные для определения времени выполнения
	printf("Введите размер  матрицы \n");
	scanf_s("%d", &m);
	int** a = new int* [m];
	int** b = new int* [m];
	int** c = new int* [m];
	for (int i = 0; i < m; ++i) {
		a[i] = new int[m];
		b[i] = new int[m];
		c[i] = new int[m];
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i< m)
	{
		while (j< m)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i< m)
	{
		while (j< m)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	start = clock();
#pragma omp for num_threads(16) collapse(2)

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			elem_c = 0;
#pragma omp critical
			for (r = 0; r < m; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
				
			}
		}
	}
	float mm = 1 / (1.8 * pow(10, 9));
	end = clock();
	printf("время в тактах\n");
	printf("%f\n", end - start / (CLOCKS_PER_SEC/mm));
	printf("время в секундах\n");
	printf("%f\n", float(end - start) / float(CLOCKS_PER_SEC));
	return 0;
}