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
    vector<int> even;
    vector<int> odd;
    for (int i = 0; i < n; i++)
    {
        int x = read();
        if (x % 2 == 0)
        {
            even.push_back(x);
        }
        else
        {
            odd.push_back(x);
        }
    }
    if (even.size() == 0 or odd.size() == 0)
    {
        cout << 0 << endl;
        return;
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    int modd = odd[odd.size() - 1];

    int ans = even.size();
    for(int i=0;i<even.size();i++){
        if(even[i]<modd){
            modd+=even[i];
        }else{
            ans+=1;
            break;
        }

    }
    cout << ans << endl;
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