// #include<bits/stdc++.h>
#include<iostream>
#include<Algorithm>
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


void solve()
{
    int n = read(), lv = read(), rv = read();
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = read();
    }
    int l = 0, r = 0, sum = 0, cnt = 0;
    while (r < n) {
        sum += a[r];
        if(sum >= lv){
            while (sum > rv && l <= r && sum >= lv) {
                sum -= a[l];
                l++;
            }
            if (sum >= lv && sum <= rv) {
                cnt++;
                r++;
                l=r;
                sum=0;
                continue;
            }
        }
        r++;
    }
    write(cnt);
    cout << endl;
}
 

signed main() {
    int n = read();
    while (n--)
    {
        solve();
    }
    
    return 0;
}