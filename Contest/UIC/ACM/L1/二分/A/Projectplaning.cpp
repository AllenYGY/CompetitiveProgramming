#include <bits/stdc++.h>
#define int long long
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
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
signed main()
{

    int N=read(),K=read();
    int a[N + 1], i = 1;
    while (i <= N) a[i++]=read();
    int l = 0, r = (1e18) / K, mid;
    while (l <= r)
    {
        mid = (l + r) / 2; int s = 0;
        for (int i = 1; i <= N; ++i) s += min(a[i], mid);
        if (s >= mid * K) l = mid + 1;
        else r = mid - 1;
    }
    write(r);
    return 0;
}