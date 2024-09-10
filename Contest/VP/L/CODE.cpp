#include<bits/stdc++.h>
#include<iostream>
#define int long long
#define endl '\n'
using namespace std;
#define  PII pair<int,int>
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
    int n=read(),x=read(),y=read();
    int left=x,right=n-x+1;
    int up=y,down=n-y+1;
    int a[4]={left,right,up,down};
    vector<PII> v = {{left,1},{right,2},{up,3},{down,4}};
    sort(v.begin(),v.end());
    v[0].second;


    sort(a,a+4);
    int side =a[1];
    cout<<"Yes"<<endl;
    cout<<n-1<<endl;


}

signed main() {
 
    return 0;
}