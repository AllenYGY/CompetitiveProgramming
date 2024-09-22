#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

void solve(){
    int n = read(), k = read();
    int ans = ((2*n-k+1)*k/2)%2;

    if (ans % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    int T = read();
    while (T--) {
        solve();
    }
    return 0;
}