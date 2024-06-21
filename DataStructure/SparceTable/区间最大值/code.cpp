#include<bits/stdc++.h>
#include<iostream>
#define int long long
#define endl '\n'
using namespace std;
 

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}


signed main(){
    int n=read(), m=read(), stmax[n+1][21],stmin[n+1][21];
    for(int i=1;i<=n;++i) stmax[i][0]=read(),stmin[i][0]=stmax[i][0];
    for(int j =1;j<=21;++j){
        for(int i =1;i<=n;++i){
            if(i+(1<<j)-1>n) continue;
            stmax[i][j]= max(stmax[i][j-1],stmax[i+(1<<(j-1))][j-1]);
            stmin[i][j]= min(stmin[i][j-1],stmin[i+(1<<(j-1))][j-1]);
        }
    }
    while(m--){
        int l=read(),r=read();
        int k = log2(r-l+1);
        cout<<max(stmax[l][k],stmax[r-(1<<k)+1][k])<<endl;
        // int a=min(stmin[l][k],stmin[r-(1<<k)+1][k]);
    }
    return 0;
}