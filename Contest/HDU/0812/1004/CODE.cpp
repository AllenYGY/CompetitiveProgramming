#include<bits/stdc++.h>
#include<iostream>
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
 
void write(int x){
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

void solve() {
    int n = read(), m = read(), a = read(), b = read();
    if(n<=2 or m<=2){
        cout<<min(n,m)*max(n,m)<<endl;
        return;
    }
    int max_cells;
    if ((a == 1 || a == n) && (b == 1 || b == m)) { // 4 corners
        max_cells = 2 * (n + m) - 4;
    } else if (a == 1 || a == n) { // Row
        max_cells=2*(n+m)-4+(n-2);
    } else if (b == 1 || b == m) { // Column
        max_cells=2*(n+m)-4+(m-2);
    } else { // center
        max_cells = max(2 * (n + m) - 4 + (m - 2), 2 * (n + m) - 4 + (n - 2));
    }

    cout << max_cells << endl;
}
signed main() {
    int T = read();
    while (T--) {
        solve();
    }
    return 0;
}