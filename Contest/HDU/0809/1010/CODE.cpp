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
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T=read();
    while(T--) {
        int n, x, k;
        n=read(),x=read(),k=read();
        priority_queue<int> pq;
        int i;
        int a[n];
        for(i = 0; i < n; i++) {
            a[i]=read();
        }
        for(i = 0; i < n; i++) {
            x -= a[i];
            pq.push(a[i]);
            while(x <= 0 && k > 0) {
                x += pq.top();
                pq.pop();
                k--;
            }
            if(x <= 0) {
                break;
            }
        }
        cout << i << endl;
    }
    return 0;
}
