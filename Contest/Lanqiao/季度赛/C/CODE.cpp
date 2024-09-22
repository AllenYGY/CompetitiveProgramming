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

}
 
signed main() {
    int n = read();
    vector<int> m(n);
    vector<int> f(n);
    for(int i=0;i<n;i++){
        m[i]=read();
    }
    for(int i=0;i<n;i++){
        f[i]=read();
    }
    sort(m.begin(),m.end());
    sort(f.begin(),f.end(),greater<int>());
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        ans[i]=m[i]+f[i];
    }
    sort(ans.begin(),ans.end());

    cout<<ans[0]<<endl;

    return 0;
}