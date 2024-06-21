#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 20, md = 1e9 + 7;
int a[N];
int f[N][9 * 18 + 5];
int T;

int dfs(int pos, bool limit, int sum)
{
    if(!pos) 
        return sum;
    if(!limit && ~f[pos][sum]) 
        return f[pos][sum];
    int up = limit ? a[pos] : 9;
    int res = 0;
    for(int i = 0; i <= up; i ++)
        res = (res + dfs(pos - 1, limit && i == up, sum + i)) % md;
    if(!limit) 
        f[pos][sum] = res;
    return res;
}

int solve(int x)
{
    int len = 0;
    while(x > 0)
    {
        a[++ len] = x % 10;
        x /= 10;
    }
    return dfs(len, true, 0); 
}
signed main()
{   
    cin >> T;
    memset(f, -1, sizeof f);
    while(T --)
    {
        int  r;
        cin >> r;
        int ans = (solve(r) - solve(0) + md) % md;
        if(ans < 0)
            ans += md;
        cout << ans << '\n';
    }
}