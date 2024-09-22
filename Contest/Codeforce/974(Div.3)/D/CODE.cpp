// #include <bits/stdc++.h>
// #include <iostream>
// // #define int long long
// #define endl '\n'
// using namespace std;

// int read()
// {
//     int x = 0, f = 1;
//     char ch = getchar();
//     while (ch < '0' || ch > '9')
//     {
//         if (ch == '-')
//             f = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9')
//         x = x * 10 + ch - '0', ch = getchar();
//     return x * f;
// }

// void write(int x)
// {
//     if (x < 0)
//         putchar('-'), x = -x;
//     if (x > 9)
//         write(x / 10);
//     putchar(x % 10 + '0');
// }

// void insert(int l, int r, int c, vector<int> &b)
// {
//     b[l] += c;
//     b[r + 1] -= c;
// }

// const int N = 2e5 + 5;

// // vector<int> b(N, 0);

// void solve()
// {
//     int n = read(), d = read(), k = read();
//     vector<int> a(n + 1, 0);
//     vector<int> b(n + 1, 0);
//     for (int i = 0; i < k; i++)
//     {
//         int l = read(), r = read();
//         b[l]++;
//         b[r]++;
//         insert(l, r, 1, a);
//     }
//     for (int i = 1; i <= n; i++){
//         a[i] += a[i - 1];
//     }

//     int maxn = b[1];
//     int minn = a[1];
//     for (int i = 2; i <= d; i++)
//     {
//         maxn += b[i];
//         minn += a[i];
//     }
//     // cout<<minn<<" "<<maxn<<endl;
//     int bday = 1, mday = 1;

//     int tmp1 = maxn;
//     int tmp2 = minn;

//     for (int i = d + 1; i <= n; i++)
//     {
//         tmp1 = tmp1 - b[i - d] + b[i];
//         tmp2 = tmp2 - a[i - d] + a[i];
//         // cout<<tmp1<<" "<<tmp2<<endl;6
//         if (maxn < tmp1)
//         {
//             maxn = tmp1;
//             bday = i - d + 1;
//             // cout<<"Maxn Change!!!"<<" "<<i<<endl;
//         }
//         if (minn > tmp2)
//         {
//             minn = tmp2;
//             mday = i - d + 1;
//             // cout<<"Minn Change!!!"<<" "<<i<<endl;
//         }
//     }


//     cout << bday << " " << mday << endl;
// }

// signed main()
// {
//     int T = read();
//     while (T--)
//     {
//         solve();
//     }
//     return 0;
// }

//D
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5+5, inf = 1e18;

int a[maxn];

void solve(){
    int n, d, k;
    cin >> n >> d >> k;
    for ( int i = 1; i <= k; i++ ){
        int l, r;
        cin >> l >> r;
        l = max(1LL, l - d + 1);
        // r = min(r, n - d + 1);
        a[l]++;
        a[r + 1]--;
    }

    for ( int i = 1; i <= n - d + 1; i++ ){
        a[i] += a[i - 1];
    }
    
    int mx = 0, mn = inf, ansmx, ansmn;
    for ( int i = 1; i <= n-d+1; i++ ){
        if ( a[i] > mx ){
            mx = a[i];
            ansmx = i;
        }
        if ( a[i] < mn ){
            mn = a[i];
            ansmn = i;
        }
    }

    cout << ansmx << " " << ansmn << endl;

    memset(a, 0, sizeof(a));
}

signed main(){
    int t;
    cin >> t;
    while ( t-- ){
        solve();
    }
    return 0;
}