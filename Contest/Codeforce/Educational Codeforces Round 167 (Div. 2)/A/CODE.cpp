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

void WMH(){
    int x,y;
    cin>>x>>y;
    int tmp = x>=0?x:-x;
    if(y-tmp+1>=-tmp) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
} 

signed main() {
    int t = read();
    while(t--){
        WMH();
    }
    return 0;
}