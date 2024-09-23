/*Дівчинка Іринка щиро вірить в те, що Ви вже досконало знаєте
прості сортування. Але вони дуже повільні, а чекати дуже
нудно… Тому вона просить Вас, як свого друга, розважити її.
Щоб розважити Іринку напишіть пірамідальне сортування.
Спочатку виведіть дерево (кучу), де всі батьки не більші за
своїх синів, а потім масив, відсортований у порядку
незростання.*/

#include <iostream>
using namespace std;

void in_mas(int mas[], int N) {
    for (int i = 1; i <= N; i++) {
        cin >> mas[i];
    }
}

void out_mas(int mas[], int N) {
    for (int i = 1; i <= N; i++) {
        cout << mas[i] << " ";
    }
    cout << '\n';
}

void restoreheap(int mas[], int father, int cnt_last) 
{
    int minson;
    while (father <= cnt_last/2)
    {
        minson = father * 2;
        if (minson + 1 <= cnt_last && mas[minson + 1] < mas[minson]) 
            minson++;
        if (mas[father] > mas[minson]) 
        {
            swap(mas[father], mas[minson]);
            father = minson;
        } 
        else return;
    }
}


void heap_sort(int mas[], int N, bool comporator)
{
    for (int i = N / 2; i >= 1; i--)
        restoreheap(mas, i, N);
    out_mas(mas, N);
    
    if (!comporator)
    {
        for (int i = N; i > 1; i--)
        {
            swap(mas[1], mas[i]);
            restoreheap(mas, 1, i - 1);
        }
    }
}

/*bool comp(int a[], int b[])
{
    if(a[1]>b[1]) return true;
    return false;
}

void restoreheap(int mas[], int father, int cnt_last) 
{
    int minson;
    while (father <= cnt_last/2)
    {
        minson = father * 2;
        if (minson + 1 <= cnt_last && comp(mas[minson] , mas[minson+1])) 
            minson++;
        if (comp(mas[father] , mas[minson])) 
        {
            swap(mas[father], mas[minson]);
            father = minson;
        } 
        else return;
    }
}


void heap_sort(int mas[], int N, bool comporator)
{
    for (int i = N / 2; i >= 1; i--)
        restoreheap(mas, i, N);
    out_mas(mas, N);
    
    
    for (int i = N; i > 1; i--)
    {
        swap(mas[1], mas[i]);
        restoreheap(mas, 1, i - 1);
    }
    
}*/

int mas[1000000];
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    in_mas(mas, N);
    heap_sort(mas, N, false);
    out_mas(mas, N);
    return 0;
}

