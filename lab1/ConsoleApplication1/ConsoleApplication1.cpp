#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    
    setlocale(LC_ALL, "");
    int n, m,summa_strok, raznost, min = 1000, max = 0;
    cout << "--------------------------------------------------------------------\n";
    cout << "Введите длину строк в массиве: ";
    cin >> n;
    cout << "--------------------------------------------------------------------\n";
    cout << "Введите длину столбцов в массиве: ";
    cin >> m;
    cout << "--------------------------------------------------------------------\n";
    cout << "Строк в массиве: " << n << "\n";
    cout << "Столбцов в массиве: " << m << "\n";
    cout << "--------------------------------------------------------------------\n";
    int* kletka = new int[n * m];
    int* summastr = new int[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            kletka[i * j] = rand() % 100;

        }
    }
        cout << "Вывод массива:\n ";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
               
                if (i != n - 1 || j != m - 1) {
                    cout << kletka[i * j] << ",";
                }
                else {
                   cout << kletka[i * j] << "\n";
                }
                
                   
                

            }
        }
        cout << "--------------------------------------------------------------------\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (kletka[i * j] <= min) {
                    min = kletka[i * j];


                }
                if (kletka[i * j] >= max) {
                    max = kletka[i * j];


                }
            }
        }


        for (int j = 0; j < n; j++) {
            summa_strok = 0;
            for (int i = 0; i < m; i++)
                summa_strok += kletka[i*j];
            summastr[j] = summa_strok;
        }
        cout << "Вывод массива с суммой каждой строки:\n ";
        for (int j = 0; j < n; j++) {
            if (j != n - 1) {
                cout << summastr[j] << ",";
            }else{
                cout << summastr[j] << "\n";
            }
        }
        cout << "--------------------------------------------------------------------\n";
        delete [] kletka;
        kletka = nullptr;
        delete[] summastr;
        summastr = nullptr;
        cout << "Максимальное:" << max << "\n" << "Минимальное:" << min << "\n";
        cout << "--------------------------------------------------------------------\n";
        raznost = max - min;
        cout << "Разность минимального и максимального: " << raznost << "\n";
        cout << "--------------------------------------------------------------------\n";
    }


