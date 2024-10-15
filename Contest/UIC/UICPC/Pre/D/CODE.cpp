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
 
void write(int x){
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}


signed main() {
    int n=read();
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        a[i]=read();
    }
    
    unordered_map<int, int> remainder_cnts;

    for (int i = 0; i < n; ++i) {
        int remainder = a[i] % 200;
        remainder_cnts[remainder]++;
    }

    int ans = 0;
    for (const auto& cnt : remainder_cnts) {
        if (cnt.second > 1) {
            ans += cnt.second * (cnt.second - 1) / 2;
        }
    }

    cout << ans << endl;

    return 0;
}
