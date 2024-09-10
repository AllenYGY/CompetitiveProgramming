#include <bits/stdc++.h>
#include <iostream>
#define int long long
#define endl '\n'
using namespace std;

signed main()
{
    int f[1001][2], n, i, x = 9;
    cin >> n;
    f[1][1] = 1;
    f[1][0] = 9;
    for (i = 2; i <= n; i++)
    {
        if (i == n) x--;
        f[i][0] = (f[i - 1][0] * x + f[i - 1][1]) % 12345;
        f[i][1] = (f[i - 1][1] * x + f[i - 1][0]) % 12345;
    }
    cout << f[n][0];
    return 0;
}
