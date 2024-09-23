/*Тривав черговий день Школи програмування та інформаційних технологій. Максиму
було смертельно нудно… «Чим би зайнятися? – нудьгував Максим. І тут на очі йому
потрапила велика коробка з крейдою. «Евріка!» - вигукнув Максим і терміново
відправився малювати лінії на асфальті. Під час роботи до нього приєднався Тимофій
і хлопці почали наввипередки малювати відрізки, змагаючись у кого буде довший.
Через певний час з’ясувалося, що крейда закінчилася, а на доріжках табору з’явилося
багато відрізків, розташованих на одній прямій. Частина з них накладалася один на
одного, але й були незафарбовані ділянки. Льова зацікавився цими лініями і оскільки
вони з Борею, як математики, не можуть не створити задачу на рівному місці, блакитна
паралель отримала чергове завдання.
Отже, відомі координати лівих та правих кінців відрізків на координатній прямій.
Потрібно знайти довжину зафарбованої частини числової прямої.*/

#include <iostream>
using namespace std;

void in_2dmas(int mas[][3], int row){
    for (int i = 1; i <= row; i++){
        for (int j = 1; j <= 2; j++){
            cin >> mas[i][j];
        }
    }
}

void out_2dmas(int mas[][3], int row){
    for (int i = 1; i <= row; i++){
        for (int j = 1; j <= 2; j++){
            cout << mas[i][j] << " ";
        }
        cout << '\n';
    }
}

bool comp(int a[], int b[])
{
    if(a[1]<b[1]) return true;
    return false;
}

void restoreheap(int mas[][3], int father, int cnt_last) 
{
    int minson;
    while (father <= cnt_last/2)
    {
        minson = father * 2;
        if (minson + 1 <= cnt_last && comp(mas[minson], mas[minson+1])) 
            minson++;
        if (comp(mas[father], mas[minson])) 
        {
            swap(mas[father], mas[minson]);
            father = minson;
        } 
        else return;
    }
}


void heap_sort(int mas[][3], int N)
{
    for (int i = N / 2; i >= 1; i--)
        restoreheap(mas, i, N);
    

    for (int i = N; i > 1; i--)
    {
        swap(mas[1], mas[i]);
        restoreheap(mas, 1, i - 1);
    }
}

int mas[15000][3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, cnt, etalon = 1;
    cin >> N;
    in_2dmas(mas, N);
    heap_sort(mas, N);

    cnt = mas[1][2] - mas[1][1];

    for (int i = 2; i <= N; i++)
    {
        if (mas[i][1] < mas[etalon][2])
        {
        
            if (mas[i][2] > mas[etalon][2])
            {
                cnt += mas[i][2] - mas[etalon][2];
                etalon = i;
            }
        }
        else
        {
            cnt += mas[i][2] - mas[i][1];
            etalon = i;
        }
    }
    cout << cnt;
    return 0;
}