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

int fastpow(int a,int n){
    int ans=1;
    while(n){
        if(n&1) ans*=a;
        a*=a;
        n>>=1;
    }
    return ans;
}

int fastpowmod(int a,int n,int mod){
    int ans=1;
    a%=mod;
    while(n){
        if(n&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        n>>=1;
    }
    return ans;
}

void solve(){
       
}
 
signed main() {
 
    return 0;
}