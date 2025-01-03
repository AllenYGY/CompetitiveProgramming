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
    if(n==1){
        int res=read();
        cout<<res<<endl;
        return;
    }
    vector<int> v(n);
    int sum=0;
    for(int i=0;i<n;i++){
        v[i]=read();
        sum+=v[i];
    }
    
    sort(v.begin(),v.end());
    for(int i=1;i<v.size();i++){
        if(v[i]-1==v[i-1]){
            cout<<-1<<endl;
            return;
        }
    }



}
 
signed main() {
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}