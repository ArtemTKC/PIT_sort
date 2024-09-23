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

void bubble_last_dig_sort_mas(int mas[], int N)
{
    int dig, dig2;
    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++)
        {
            dig=mas[i]%10;
            dig2=mas[j]%10;
            if (dig>dig2)
                swap(mas[i], mas[j]);
            if (dig==dig2)
                if (mas[i]>mas[j]) swap(mas[i], mas[j]);
            
        }
    }
}


int main()
{
    int N;
    cin >> N;
    int mas[N]; 
    in_mas(mas, N);
    bubble_last_dig_sort_mas(mas, N);
    out_mas(mas, N);
    return 0;
}