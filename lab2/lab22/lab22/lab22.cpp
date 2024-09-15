#include<locale.h>
#include<time.h>
#include <iostream>

using namespace std;

void shell(int* items, int count) {
    int gap;
    for (gap = count / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < count; ++i) {
            int temp = items[i];
            int j = i - gap;
            while ((j >= 0) && (items[j] > temp)) {
                items[j + gap] = items[j];
                j -= gap;
            }
            items[j + gap] = temp;
           
        }
    }

}
void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
    int i, j;
    int x, y;



    i = left; j = right;

    /* выбор компаранда */
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}



int main()
{
    setlocale(LC_ALL, "");
    clock_t start, end;
    int n, emoe;
    printf("Введите количество чисел в массиве\n");
    scanf_s("%d", &n);
    int* a = new int[n];
    int* vozrast = new int[n];
    int* ubiv = new int[n];
    int* smechani = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
        vozrast[i] = rand() % 41;
    } for (int i = 0; i < n; i++) {
        for (int j = n;j > 0; j--) {

              vozrast[i] = j;
    }
}
    for (int i = 0; i < (n / 2); i++) {
        smechani[i]=rand() % 41;
    }
    
    for (int j = (n/2); j > 0; j--) {

            smechani[j] = j;
        
    }
    float mm = 1 / (1.8 * pow(10, 9));
    printf("Введите какой режим хотите\n1.Алгоритм Шелла(случайные числа)\n2.Быстрая сортировка(случайные числа)\n3.Алгоритм Шелла(возрастающие числа)\n4.Быстрая сортировка(возрастающие числа)\n5.Алгоритм Шелла(убывающие числа)\n6.Быстрая сортировка(убывающие числа)\n7.Алгоритм Шелла(убывающие и возрастающие числа числа)\n8.Быстрая сортировка(убывающие и возрастающие числа)\n9.qsort\n");
    scanf_s("%d", &emoe);
    switch (emoe) {
    case 1:
        start = clock();
        shell(a, n);
        end = clock(); 
        printf("время в секундах\n");
        printf("%f\n", float(end - start) / float(CLOCKS_PER_SEC));
        break;
    case 2:
        start = clock();
        qs(a, 0, n - 1);
        end = clock();
        printf("время в секундах\n");
        printf("%f\n", float(end - start) / float(CLOCKS_PER_SEC));
        break;

    case 3:
        start = clock();
        shell(vozrast, n);
        end = clock();
        printf("время в секундах\n");
        printf("%f\n", float(end - start) / float(CLOCKS_PER_SEC)); 
        break;
    case 4:
        start = clock();
        qs(vozrast, 0, n - 1);
        end = clock();
        printf("время в секундах\n");
        printf("%f\n", float(end - start) / float(CLOCKS_PER_SEC)); 
        break;
    case 5:
        start = clock();
        shell(ubiv, n);
        end = clock();
        printf("время в секундах\n");
        printf("%f\n", float(end - start) / float(CLOCKS_PER_SEC));
        break;
    case 6:
        start = clock();
        qs(ubiv, 0, n - 1);
        end = clock();
        printf("время в секундах\n");
        printf("%f\n", float(end - start) / float(CLOCKS_PER_SEC));
        break;
    case 7:
        start = clock();
        shell(smechani, n);
        end = clock();
        printf("время в секундах\n");
        printf("%f\n", float(end - start) / float(CLOCKS_PER_SEC));
        break;
    case 8:
        start = clock();
        qs(smechani, 0, n - 1);
        end = clock();
        printf("время в секундах\n");
        printf("%f\n", float(end - start) / float(CLOCKS_PER_SEC));
        break;
    case 9:
        int emoe1;
        printf("Введите какой режим хотите для qsort\n1.случайные числа\n2.возрастающие числа\n3.убывающие числа\n4.убывающие и возрастающие числа числа\n");
        scanf_s("%d", &emoe1);
        switch (emoe1)
        {
                
        case 1:
            start = clock();
            qsort(a,n,sizeof(int),compare);
            end = clock();
            printf("время в секундах\n");
            printf("%f\n", float(end - start) / float(CLOCKS_PER_SEC));
            break;
        case 2:
            start = clock();
            qsort(vozrast, n, sizeof(int), compare);
            end = clock();
            printf("время в секундах\n");
            printf("%f\n", float(end - start) / float(CLOCKS_PER_SEC));
            break;

        case 3:
            start = clock();
            qsort(ubiv, n, sizeof(int), compare);
            end = clock();
            printf("время в секундах\n");
            printf("%f\n", float(end - start) / float(CLOCKS_PER_SEC));
            break;
        case 4:
            start = clock();
            qsort(smechani, n, sizeof(int), compare);
            end = clock();
            printf("время в секундах\n");
            printf("%f\n", float(end - start) / float(CLOCKS_PER_SEC));
            break;

        }
}
     return 0;
}