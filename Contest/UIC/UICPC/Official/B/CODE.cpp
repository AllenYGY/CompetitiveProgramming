#include <bits/stdc++.h>
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
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();

    return x * f;
}

vector<int> Ss;
vector<int> loc;

void getvalue(vector<int> &psum, int l, int r)
{
    if (r < l)
        cout << 0 << endl;
    else
        cout << psum[r] - psum[l - 1] << endl;
}

void solve()
{
    int N = read();
    vector<pair<int, int>> X;
    for (int i = 0; i < N; i++)
    {
        int fir = read();
        X.push_back({fir, 0});
    }
    for (int i = 0; i < N; i++)
    {
        int sec = read();
        X[i].second = sec;
    }
    sort(X.begin(), X.end());
    for (int i = 0; i < X.size(); i++)
        loc.push_back(X[i].first);
    for (int i = 0; i < X.size(); i++)
        Ss.push_back(X[i].second);
    vector<int> PreSum(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        PreSum[i] = (PreSum[i - 1] + Ss[i - 1]);
    }
    int T = read();
    while (T--)
    {
        int l = read(), r = read();
        int left = lower_bound(loc.begin(), loc.end(), l) - loc.begin();
        int right = upper_bound(loc.begin(), loc.end(), r) - loc.begin();
        cout << PreSum[right] - PreSum[left] << endl;
    }
}

signed main()
{

    solve();
    return 0;
}
