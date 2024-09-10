#include <bits/stdc++.h>
#include <iostream>
#define int long long
#define endl '\n'
using namespace std;

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

void write(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

int qpow(int a, int b, int p)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ((ans % p) * (a % p)) % p;
        a = ((a % p) * (a % p)) % p;
        b >>= 1;
    }
    return ans;
}

int MOD = 998244353;

void solve(int i)
{
    // int n = read();
    int n = i;
    if(n==1) {
        cout<<2<<endl; return ;
    }
    if(n==2) {
        cout<<2<<endl; return ;
    }
    if(n==3) {
        cout<<8<<endl; return ;
    }
    int ans=0;

    int power = n ;
    ans= qpow(2,power%(MOD-1),MOD)%MOD;
    cout<<ans<<endl;
}

signed main()
{
    int T = read();
    for(int i=1;i<=50;i++) {
        solve(i);
    }
    // while (T--)
    // {
    //     solve();
    // }
    return 0;
}

