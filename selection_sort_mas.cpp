/*Те, що Іринка дуже полюбляє сортування і тому дружить тільки з тими
хто знає усі їх різновиди, Ви вже, мабуть знаєте? Однак сортування
Бульбашкою, на її погляд, є занадто простим. Тому, щоб довести, що
Ви знаєте сортування трохи краще ніж на елементарному рівні,
потрібно продемонструвати знання ще одного сортування –
сортування прямим вибором. Для цього напишіть програму, яка
підраховує, скільки разів під час сортування змінював своє місце
елемент, який спочатку знаходився на першій позиції. Чи зможете Ви
стати другом Іринки? */


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

int selection_sort_mas(int mas[], int N)
{
    int count_first_elem_swaps = 0; 
    int first_elem_index = 0; 

    for (int i = 0; i < N; i++)
    {
        int etalon = i; 
        for (int j = N-1; j >= i; j--)
        {
            if (mas[j] > mas[etalon])
            {
                etalon = j; 
            }
        }
        
        
        if ((i == first_elem_index) and (mas[i]!=mas[etalon]))
        {
            count_first_elem_swaps++;
            first_elem_index=etalon;
        }
        else if((etalon == first_elem_index) and (mas[i]!=mas[first_elem_index]))
        {
            count_first_elem_swaps++;
            first_elem_index=i;
        }
        swap(mas[etalon], mas[i]);          
    }
    return count_first_elem_swaps;
}


int main()
{
    int N;
    cin >> N;
    int mas[N]; 
    in_mas(mas, N);
    cout << selection_sort_mas(mas, N) << '\n';
    out_mas(mas, N);
    return 0;
}