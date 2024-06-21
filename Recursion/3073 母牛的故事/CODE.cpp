#include <bits/stdc++.h>
#include <iostream>
#define int long long
#define endl '\n'
using namespace std;

const int MOD = 1000;
const int MAXN = 1000000;

int val[MAXN] = {0};

void solve(int x)
{

    if(val[x]!=0){
        cout << val[x] << endl;
        return;
    }
    val[1]=1;
    val[2]=2;
    val[3]=3;
    for(int i=4;i<=x;i++){
        val[i]=(val[i-1]+val[i-3]);
    }
    cout << val[x] << endl;
}

signed main()
{
    int x;
    cin >> x;
    while (x)
    {
        solve(x);
        cin >> x;
    }
    return 0;
}