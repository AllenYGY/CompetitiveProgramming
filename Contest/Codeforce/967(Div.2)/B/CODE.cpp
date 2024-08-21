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

void solve(){
    int n=read();
    if(n%2==0){
        write(-1);
        cout<<endl;
        return;
    }
    for(int i=n;i>=1;i-=2){
        write(i);
        cout<<" ";
    }
    for(int i=2;i<=n-1;i+=2){
        write(i);
        cout<<" ";
    }
    cout<<endl;

}

signed main() {
    int T = read();
    while(T--){
        solve();    
    }
    return 0;
}