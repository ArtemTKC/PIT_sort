#include <iostream>
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

int bubble_sort_mas(int mas[], int N)
{
    int cnt=0;
    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++)
        {
            if (mas[i]>mas[j])
            {
                swap(mas[i], mas[j]);
                cnt++;
            }
        }
    }
    return cnt;
}


int main()
{
    int N, cnt;
    cin >> N;
    int mas[N]; 
    in_mas(mas, N);
    cnt=bubble_sort_mas(mas, N);
    cout << cnt << '\n';
    out_mas(mas, N);
    return 0;
}