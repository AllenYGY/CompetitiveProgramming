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
    string s,t;
    cin>>s>>t;
    vector<pair<int, char>> m;
    for(int i=0;i<s.size();i++){
        m.push_back({i,s[i]});
    }
    for(int i=0;i<t.size();i++){
        if(t[i]-'0'>=0&&t[i]-'0'<=9){
           cout<<m[t[i]-'0'].second;
        }
        else cout<<t[i];
    }
    // cout<<t<<endl;
    return 0;
}