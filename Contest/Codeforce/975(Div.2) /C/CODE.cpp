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
    vector<int> a(n);
    for(int i=0;i<n;i++){
        a[i]=read();
    }

    if(n==1 || n==2){
        cout<<-1<<endl;
        return;
    }
    sort(a.begin(),a.end());
    int avg_idx=a.size()/2;
    int avg=2*a[avg_idx];
    int res=0;
    // cout<<avg<<endl;
    for(int i=0;i<=avg_idx;i++){
        res+=(avg-a[i]);
    }
    // cout<<res<<endl;
    for(int i=avg_idx+1;i<n;i++){
        res+=(avg-a[i]);
    }
    res+=1;
    if(res<=0){
        cout<<0<<endl;
        return;
    }
    cout<<res<<endl;

}
 
signed main() {
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}