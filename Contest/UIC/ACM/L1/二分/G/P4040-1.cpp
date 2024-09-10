#include <bits/stdc++.h>
#define int long long
using namespace std;

int m,f,n;

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




signed main()
{
    m=read(),f=read(),n=read();
    int p[n+1],s[n+1],i=1;
    memset(p,0,sizeof(p));  memset(s,0,sizeof(s));
    while(i<=n) p[i]=read(),s[i]=read(),i++;
    
    return 0;
}

