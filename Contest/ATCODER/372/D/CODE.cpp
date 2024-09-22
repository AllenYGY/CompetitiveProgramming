#include<bits/stdc++.h>
#include<iostream>
// #define int long long
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
    int n=read();
    vector<int> H(n+1);
    for(int i=1;i<=n;i++){
        H[i]=read();
    }
    vector<int> ans(n,0);
    vector<int> st;
    for(int i=n;i>=1;i--){
        ans[i]=st.size();
        while(st.size() and st.back()<H[i]){
            st.pop_back();
        }
        st.push_back(H[i]);

    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}