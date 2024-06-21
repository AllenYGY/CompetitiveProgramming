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
int n, m;

int check(int che, int r[], int d[], int s[], int t[])
{
    int i=1,Sum=0,maxSum=0;
    int num=t[che]-s[che]+1;
    Sum=num*d[che];
    while(i<=t[che]){

        maxSum+=r[i];
        i++;
    }
    cout<<Sum<<" "<<maxSum<<endl;
    if (Sum<=maxSum)
        return 0;
    else 
        return che;
}

signed main()
{
    n = read(), m = read();
    int r[n + 1], d[m + 1], s[m + 1], t[m + 1], i = 1;
    while (i <= n)
        r[i++] = read();
    i = 1;
    while (i <= m)
        d[i] = read(), s[i] = read(), t[i] = read(), i++;
    i = 1;
    int left = 1, right = m, mid, ans = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (check(mid, r, d, s, t))
            ans = mid, right = mid - 1,cout<<ans<<endl;
        else
            left = mid + 1;
    }
    if (ans)
        cout << -1 << endl
             << ans;
    else
        cout << 0;
    return 0;
}

// 10 10 1475400
// 23954 25180
// 18805 2701
// 17195 5663
// 7044 13659
// 8139 30927
// 19774 25516
// 7472 4572
// 5999 6166
// 1185 13621
// 10414 26521
// 2 10
// 4 7
// 5 8
// 1 6
// 2 7
// 1 3
// 2 7
// 3 4
// 1 6
// 1 10

// -1
// 6

// 4 3 
// 2 5 4 3 
// 2 1 3 
// 3 2 4 
// 4 2 4