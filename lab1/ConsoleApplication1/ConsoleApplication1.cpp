﻿#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    int n, raznost,min = 1000,max=0;
    n = 10;
   
    cout << "--------------------------------------------------------------------\n";
    cout << "Cимволов в массиве: " << n << "\n";
    cout << "--------------------------------------------------------------------\n";
    int kletka[10] = { };
    for (int i = 0; i < n; i++)
    {
        kletka[i] = rand()%100; 
     
    }
    cout << "Вывод массива: ";
    for (int i = 0; i < n; i++) {
        if (i != n-1) {
            cout << kletka[i] << ",";
        }
        else {
            cout << kletka[i] << "\n";
        }
        }
    cout << "--------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        
        if (kletka[i] <= min) {
            min = kletka[i];           
           
            
        }
        if (kletka[i] >= max) {
            max = kletka[i];        
            
            
        }
    }
    cout <<"Максимальное:" << max << "\n" << "Минимальное:" << min << "\n";
    cout << "--------------------------------------------------------------------\n";
    raznost = max - min;
    cout << "Разность минимального и максимального:" << raznost<<"\n";
    cout << "--------------------------------------------------------------------\n";
}

