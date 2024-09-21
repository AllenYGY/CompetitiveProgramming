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
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=read();
    }
    if(n==2){
        cout<<a[1]-a[0]<<endl;
        return;
    }
    else{
        int ans=a[n-2];
        for(int i=0;i<n-2;i++){
            ans-=a[i];
        }
        cout<<a[n-1]-ans<<endl;
    }

}
 
signed main() {
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}