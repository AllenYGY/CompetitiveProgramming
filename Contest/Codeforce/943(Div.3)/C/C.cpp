#include <bits/stdc++.h>
#include <iostream>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int res = 1;
    int a[n];
    a[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        res += tmp;
        a[i] = res;
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";  
    }
    cout << endl;
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
