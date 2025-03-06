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

void solve()
{
    int n = read();
    vector<int> a(n);
    int maxn = -1;
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        a[i] = read();
        if (a[i] >= maxn)
        {
            maxn = a[i];
            idx = i;
        }
    }
    if (n == 1)
    {
        cout << 1 + a[0] << endl;
        return;
    }
    if (a.size() % 2 == 0)
    {
        int ans = a.size() / 2;
        ans += maxn;
        cout << ans << endl;
    }
    else
    {
        int oddsize = a.size() / 2;
        int flag = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == maxn and i % 2 == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            cout << oddsize + 1 + maxn << endl;
        }
        else
        {
            int maxeven = 0;
            for (int i = 0; i < a.size(); i += 2)
            {
                maxeven = max(maxeven, a[i]);
            }
            int ans = max(oddsize + maxn, oddsize + maxeven);
            cout << ans << endl;
        }
    }
}

signed main()
{
    int T = read();
    while (T--)
    {
        solve();
    }
    return 0;
}