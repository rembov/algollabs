#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<locale.h>
#include<math.h>
int main(void)
{int i = 0, j = 0, r,m,m1,m2;
	int  elem_c, elem_c1, elem_c2;
	setlocale(LC_ALL, "");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	clock_t start, end,start1,end1,start2,end2; // объявляем переменные для определения времени выполнения
	printf("Введите размер  матрицы 1 \n");
	scanf_s("%d", &m);
	printf("Введите размер  матрицы 2 \n");
	scanf_s("%d", &m1);
	printf("Введите размер  матрицы 3 \n");
	scanf_s("%d", &m2);
	float mm = 1 / (1.8 * pow(10, 9));
	int** a = new int* [m];
	int** b = new int* [m];
	int** c = new int* [m];
	for (int i = 0; i < m; ++i) {
		a[i] = new int[m];
		b[i] = new int[m];
		c[i] = new int[m];
	}
	int** a1 = new int* [m1];
	int** b1 = new int* [m1];
	int** c1 = new int* [m1];
	for (int i = 0; i < m1; ++i) {
		a1[i] = new int[m1];
		b1[i] = new int[m1];
		c1[i] = new int[m1];
	}
	int** a2 = new int* [m2];
	int** b2 = new int* [m2];
	int** c2 = new int* [m2];
	for (int i = 0; i < m2; ++i) {
		a2[i] = new int[m2];
		b2[i] = new int[m2];
		c2[i] = new int[m2];
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i< m)
	{
		while (j< m)
		{
			a[i][j] = rand() % 100 + 1;
			a1[i][j] = rand() % 100 + 1;
			a2[i][j] = rand() % 100 + 1;// заполняем массив случайными числами
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
			b[i][j] = rand() % 100 + 1;
			b1[i][j] = rand() % 100 + 1;
			b2[i][j] = rand() % 100 + 1;// заполняем массив случайными числами
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
	
	end = clock();
	printf("время в тактах\n");
	printf("%f\n", end - start / (CLOCKS_PER_SEC/mm));
	printf("время в секундах\n");
	printf("%f\n", float(end - start) / float(CLOCKS_PER_SEC));
//////////////////////////////////////
	start1 = clock();
#pragma omp for num_threads(16) collapse(2)

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			elem_c1 = 0;
#pragma omp critical
			for (r = 0; r < m; r++)
			{
				elem_c1 = elem_c1 + a1[i][r] * b1[r][j];
				c1[i][j] = elem_c1;

			}
		}
	}

	end1 = clock();
	printf("_____________________________________________\n");
	printf("время в тактах\n");
	printf("%f\n", end1 - start1 / (CLOCKS_PER_SEC / mm));
	printf("время в секундах\n");
	printf("%f\n", float(end1 - start1) / float(CLOCKS_PER_SEC));
	//////////////////////////////////////
	start2 = clock();
#pragma omp for num_threads(16) collapse(2)

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			elem_c2 = 0;
#pragma omp critical
			for (r = 0; r < m; r++)
			{
				elem_c2 = elem_c2 + a2[i][r] * b2[r][j];
				c2[i][j] = elem_c2;

			}
		}
	}

	end2 = clock();
	printf("_____________________________________________\n");
	printf("время в тактах\n");
	printf("%f\n", end2 - start2 / (CLOCKS_PER_SEC / mm));
	printf("время в секундах\n");
	printf("%f\n", float(end2 - start2) / float(CLOCKS_PER_SEC));
	return 0;
}
