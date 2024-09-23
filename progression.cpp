/*Кожен більш-менш старанний учень знає, що таке арифметична прогресія. Тимофій це
теж знав! Він дуже швидко утворював будь-які арифметичні прогресії за відомими
першим членом та її кроком. І ось одного разу йому на очі потрапила велика
послідовність натуральних чисел. «А чи можна з неї утворити арифметичну
прогресію?» - подумав Тимофій. Очевидно, що з довільних чисел це зробити важко. А
якщо змінити порядок чисел? Допоможіть Тимофію знайти відповідь на поставлене
питання. Відповідь дати у формі YES або NO.*/

#include <iostream>
using namespace std;

int in_mas_dont_know_N(int mas[])
{
    int cnt = 0;
    while (cin >> mas[cnt])
    {
        cnt++;
    }
    return cnt;
}

void restoreheap(int mas[], int father, int cnt_last)
{
    int maxson;
    while (father * 2 + 1 <= cnt_last){
        maxson = father * 2 + 1;
        if (maxson + 1 <= cnt_last && mas[maxson + 1] > mas[maxson]) 
            maxson++;

        if (mas[father] < mas[maxson])
        {
            swap(mas[father], mas[maxson]);
            father = maxson;
        }
        else return;
    }
}


void heap_sort(int mas[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        restoreheap(mas, i, N - 1);

    for (int i = N - 1; i > 0; i--)
    {
        swap(mas[0], mas[i]);
        restoreheap(mas, 0, i - 1);
    }
}


bool is_arithmetic_progression(int mas[], int N)
{
    int d = mas[1] - mas[0]; 
    for (int i = 2; i < N; i++)
    {
        if (mas[i] - mas[i - 1] != d)
        {
            return false; 
        }
    }
    return true;
}


int mas[100000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N = in_mas_dont_know_N(mas);
    heap_sort(mas, N);
    if (is_arithmetic_progression(mas, N))
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
    return 0;
}
