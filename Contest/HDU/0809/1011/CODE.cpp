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

int gcd(int a,int b)
{
	 return b>0 ? gcd(b,a%b):a;
}

int lcm(int a,int b){
		return a/gcd(a,b)*b;
}


void solve(){
    int x=read(),y=read();
    if(x%y==0){
        cout<<y<<" "<<x/y<<endl;
        return;
    }
    int ans=lcm(2, lcm(x,y))/y;
    cout<<y<<" "<<ans<<endl;
    return;
}

signed main() {
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}