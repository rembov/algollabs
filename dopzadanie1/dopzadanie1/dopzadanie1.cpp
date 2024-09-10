#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{

    //setlocale(LC_ALL, "");
    int n, m, summa_strok, raznost, min = 1000, max = 0;
    cout << "--------------------------------------------------------------------\n";
    cout << "Vvedite dlinu strok v massive: ";
    cin >> n;
    cout << "--------------------------------------------------------------------\n";
    cout << "Vvedite dlinu stolbcov v massive: ";
    cin >> m;
    cout << "--------------------------------------------------------------------\n";
    cout << "Strok v massive: " << n << "\n";
    cout << "Stolbcov v massive: " << m << "\n";
    cout << "--------------------------------------------------------------------\n";
    //int* kletka = new int[n][m];
    int* summastr = new int[n];
    int** kletka = new int* [n];
    for (int i = 0; i < n; ++i)
        kletka[i] = new int[m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            kletka[i][j] = rand() % 100;

        }
    }
    cout << "Vivod massiva: ";
    putc('\n', stdout);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (i != n - 1 || j != m - 1) {
                cout << kletka[i][j] << ",";
            }
            else
            {
                cout << kletka[i][j];
            }
        }
        putc('\n', stdout);
    }
    cout << "--------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (kletka[i][j] <= min) {
                min = kletka[i][j];


            }
            if (kletka[i][j] >= max) {
                max = kletka[i][j];


            }
        }
    }

    summa_strok = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++)
            if (j < i) {
                summa_strok += kletka[j][i];
                //summastr[j] = summa_strok;
               // cout << summa_strok<<'\n';
            }
    }
    cout << "Vivod summi vishe glav diag: " << summa_strok << "\n";
    //cout << "Vivod massiva s summoy kajdoi stroki: " << summa_strok << "\n";
   /* for (int j = 0; j < n; j++) {
        if (j != n - 1) {
            cout << summastr[j] << ",";
        }
        else {
            cout << summastr[j] << "\n";
        }
    }*/
    cout << "--------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++)
        delete[] kletka[i];
    delete[] kletka;
    delete[] summastr;
    summastr = nullptr;
    cout << "Max:" << max << "\n" << "Min:" << min << "\n";
    cout << "--------------------------------------------------------------------\n";
    raznost = max - min;
    cout << "Raznost min i max: " << raznost << "\n";
    cout << "--------------------------------------------------------------------\n";
}
