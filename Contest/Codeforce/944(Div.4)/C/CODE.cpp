#include<bits/stdc++.h>
#include<algorithm>
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
 
void solve(){ 
    int a = read(), b = read(), c = read(), d = read();
    int la=min(a,b), ra=max(a,b), lb=min(c,d), rb=max(c,d);
    if(la<lb && ra<rb && lb<ra) cout<<"YES"<<endl;
    else if(lb<la && rb<ra && la<rb) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}
 
signed main() {
    int T = read();
    while (T--)
        solve();
    return 0;
}