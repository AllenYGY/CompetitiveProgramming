// #include<bits/stdc++.h>
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
    int x=read();
    int rnk=0;
    for(int i=1;i<32;i++){
        int tmp=read();
        if(tmp<x) rnk++;
    }
    
    if(rnk>=31) cout<<1<<endl;
    else if(rnk>=27) cout<<2<<endl;
    else if(rnk>=13) cout<<4<<endl;
    else if(rnk>=6) cout<<8<<endl;
    else if(rnk>=2) cout<<16<<endl;
    else cout<<32<<endl;

}
 
signed main() {
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}