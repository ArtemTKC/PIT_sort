/*Картмейстер Чарлі Кардмен має спеціальні колоди карт, у яких може бути до 1000000
карт. Він – „гігант думки”, тому зміг розробити багато власних ігор спеціально для таких
колод. Одного разу Чарлі запросив до себе у гості друзів і вирішив пограти з ними у
нову щойно придуману гру. Для неї необхідний був набір карт з 𝐾1,𝐾2,𝐾3, … ,𝐾𝑁. При
собі Чарлі мав колоду з картами 𝑇1, 𝑇2, 𝑇3, … , 𝑇𝑀. Йому б хотілося дізнатися, чи може він
грати у гру цією колодою. Чарлі не друкує власні карти, тому різних карт у колоді не
більше 56.test*/

#include <iostream>
using namespace std;

void cnt_mas(int mas[], int N) 
{
    int num;
    for (int i = 1; i <= N; i++) 
    {
        cin >> num;
        mas[num]++;
    }
}

void out_mas(int mas[], int N) {
    for (int i = 1; i <= N; i++) {
        cout << mas[i] << " ";
    }
    cout << '\n';
}

bool can_play(int mas1[], int mas2[])
{
    for (int i = 1; i <= 56; i++)
    {
        if (mas1[i] < mas2[i])
            return false; 
    }
    return true;
}

int cnt_need_mas[150]={0};
int cnt_have_mas[150]={0};
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N_need, N_have;

    cin >> N_need;
    cnt_mas(cnt_need_mas, N_need);

    cin >> N_have;
    cnt_mas(cnt_have_mas, N_have);

    if (can_play(cnt_have_mas, cnt_need_mas))
        cout << "Yes";
    else
       cout << "No";
       
    //out_mas(cnt_need_mas, N_need);
    //out_mas(cnt_have_mas, N_have);
    return 0;
}

