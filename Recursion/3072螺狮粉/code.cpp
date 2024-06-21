#include <bits/stdc++.h>
#include <iostream>
#define int long long
#define endl '\n'
using namespace std;

int end_day = 0;

int f(int n)
{
    int remaining = 1;
    for (int i = n; i > 1; i--)
    {
        remaining = 2 *(remaining + 1);
    }
    return remaining;
}

signed main()
{
    cin >> end_day;
    cout<< f(end_day) << endl;
    return 0;
}


// int luoshifen_1(int day)
// {
//     if (day == 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return luoshifen_1(day - 1) * 2 + 2;
//     }
// }
// void test(){
//     for(int i=2;i<30;i++){
//         int rr=f(i);
//         int cc=0;
//         while(rr>0){
//             rr/=2;
//             rr-=1;
//             cc++;
//         }
//         if(cc!=i){
//             cout<<i<<"Wrong"<<endl;
//         }
//     }
// }

