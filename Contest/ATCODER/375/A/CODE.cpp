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
    int N=read();
    string s;
    cin>>s;
    int ans=0;
    for(int i=1;i<N;i++){
        if(s[i]=='.' and s[i-1]=='#' and s[i+1]=='#'){
            ans++;
        }
    }
    cout<<ans<<endl;
    return ;
}
 
signed main() {
    solve();
    return 0;
}