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
    int n=read();
    vector<int> ans;
    while(n>=1){
        ans.push_back(n%3);
        // cout<<n%3<<endl;
        n=(n-(n%3))/3;
    }
    int N=0;
    for(int i=0;i<ans.size();i++){
        N+=ans[i];
    }
    cout<<N<<endl;
    int base = 1;
    for(int i=0;i<ans.size();i++){
        while(ans[i]--){
            cout<<i<<" ";
        }
    }
    return 0;
}