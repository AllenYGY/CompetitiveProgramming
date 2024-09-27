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
int fastpow(int a, int n) {
    int ans = 1;
    while(n){
        if(n&1) ans=ans*a;
        a=a*a;
        n>>=1;
    }
    return ans;
}

void cnm()
{
    for (int i = 1; i < 16; i++)
    {
        cout << fastpow(i, i)<<" ";
        cout << pow(i, i) << ","<<endl;
    }
}

int fastpow(int a, int n, int mod) {
    int ans = 1;
    a%=mod;
    while(n){
        if(n&1) ans=ans*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ans;
}


vector<int> ans = {0, 1, 4, 27, 
                    256, 3125, 46656, 823543, 
                    16777216, 387420489, 10000000000, 285311670611, 
                    8916100448256, 302875106592253, 11112006825558016, 437893890380859375};
signed main()
{
    // cnm();
    int n = read();
    int idx =lower_bound(ans.begin(),ans.end(),n)-ans.begin();
    if(n!=ans[idx]){
        cout<<-1;
    }else{
        cout<<idx;
    }
    return 0;
}