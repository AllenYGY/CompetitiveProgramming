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
    int a,b,c;
    cin>>a>>b>>c;
    int minn=min(a,min(b,c));
    if(a==1&&b==1&&c==1){
        cout<<"NO"<<endl;
        return;
    } int cnt=0;
    cnt=a+b+c-3;
    int sum=a+b+c-3*minn;
    if(sum%2!=0 or cnt%2!=0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return;
} 

signed main() {
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}