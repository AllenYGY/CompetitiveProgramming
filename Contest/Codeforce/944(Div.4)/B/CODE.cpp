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
    string s;
    cin >> s;
    for(int i=1;i<s.size();i++){
        if(s[i]!=s[i-1]){
            char a = s[i-1];
            s[i-1] = s[i]; 
            s[i] = a;
            cout<<"YES"<<endl;
            cout << s << endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
 
signed main() {
    int T = read();
    while(T--){
        solve();
    }
    return 0;
}