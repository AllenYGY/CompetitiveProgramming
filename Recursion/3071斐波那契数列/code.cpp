#include <bits/stdc++.h>
#include <iostream>
#define int long long
#define endl '\n'
using namespace std;

const int MOD = 1000;
const int MAXN = 1000000;

int val[MAXN] = {0};

void solve()
{
    int x;
    cin >> x;
    if(val[x]!=0){
        cout << val[x] << endl;
        return;
    }
    val[1]=1;
    val[2]=1;
    for(int i=3;i<=x;i++){
        val[i]=(val[i-1]+val[i-2])%MOD;
    }
    cout << val[x] << endl;
}

signed main()
{
    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}