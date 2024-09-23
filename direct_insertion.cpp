/*СОРТУВАННЯ ПРЯМОЮ ВСТАВКОЮ
stdin               stdout

5                   22
22 79 33 70         22 79
                    22 33 79
                    22 33 70 79
*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void in_mas(int mas[], int N){
    for (int i = 0; i < N; i++){
        cin >> mas[i];
    }
}

void out_mas(int mas[], int N){
    for (int i = 0; i < N; i++){
        cout << mas[i] << " ";
    }
    cout << '\n';
}

void insertion_sort_mas(int mas[], int N) 
{
    for (int i = 1; i < N; i++) 
    {
        //out_mas(mas, i);
        int etalon = mas[i];  
        int j = i - 1;
        while (j >= 0 && mas[j] > etalon) 
        {
            mas[j + 1] = mas[j];
            j--;
        }
        mas[j + 1] = etalon;
    }
}


int main()
{
    int N, cnt;
    cin >> N;
    int mas[N]; 
    in_mas(mas, N);
    insertion_sort_mas(mas, N);
    out_mas(mas, N);
    return 0;
}