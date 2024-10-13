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

int fastpow(int a, int n, int mod) {
    int ans = 1;
    a%=mod;
    while(n){
        if(n&1) ans=ans*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ans;
}


double getdist(double x_1,double y_1,double x_2,double y_2){
    double x=abs(x_1-x_2);
    double y=abs(y_1-y_2);
    return x*x+y*y;
}

void solve(){
    int N=read();
    double dist=0.0;
    double x_1,y_1,x_2,y_2;
    x_1=y_1=0.0;
    for(int i=0;i<N;i++){
        cin>>x_2>>y_2;
        dist+= sqrt(getdist(x_1,y_1,x_2,y_2));
        x_1=x_2;
        y_1=y_2;
    }
    x_2=y_2=0.0;
    dist+= sqrt(getdist(x_1,y_1,x_2,y_2));
    cout<<fixed<<setprecision(7)<<dist<<endl;
    return ;
}
 
signed main() {
    solve();
    return 0;
}