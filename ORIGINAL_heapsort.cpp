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
    int maxson;
    while (father <= cnt_last/2)
    {
        maxson = father * 2;
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
    for (int i = N / 2; i >= 1; i--)
        restoreheap(mas, i, N);
    //out_mas(mas, N);
    
    for (int i = N; i > 1; i--)
    {
        swap(mas[1], mas[i]);
        restoreheap(mas, 1, i - 1);
    }
    
}

int mas[1000000];
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    in_mas(mas, N);
    heap_sort(mas, N);
    out_mas(mas, N);
    return 0;
}

