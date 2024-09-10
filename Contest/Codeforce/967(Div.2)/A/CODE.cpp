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
    int n = read();
    // int a[n]={0};
    int ans=-1;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        int tmp=read();
        mp[tmp]++;
        if(ans<mp[tmp]){
            ans=mp[tmp];
        }
    }
    write(n-ans);
    cout<<endl;
}

void solve2(){
    int n=read();
    int a[1001]={-1};
    int ans=-1;
    for(int i=0;i<n;i++){
        int tmp=read();
        a[tmp]++;
        if(ans<a[tmp]){
            ans=a[tmp];
        }
    }
    write(n-ans);
    cout<<endl;
}

signed main() {
    int T = read();
    while(T--){
        solve();    
    }
    return 0;
}