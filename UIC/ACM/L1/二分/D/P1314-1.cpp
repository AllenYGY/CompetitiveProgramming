#include <bits/stdc++.h>
#define int long long
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

int getCheckValue(int l,int r,int W, vector<pair<int, int>>&v){
    int Suma = 0,Sumb=0;
    while(l<=r){
        if(v[l].first>=W){
            int a = v[l].first, b= v[l].second;
            Suma++;
            Sumb+=b;
        } 
        l++;
    }
    return Suma*Sumb;
}

signed main()
{
    int n=read(),m=read(),s=read();
    vector<pair<int, int>> v(n + 1); int i=1;
    vector<pair<int, int>> t(m + 1); 
    while(i<=n) v[i].first = read(), v[i].second = read(),i++; i=1;
    while(i<=m) t[i].first = read(), t[i].second = read(),i++; i=1;
    // int left=0,right=1e18;
    int result=1e18, ans=0, W = 0, j = 1, Y;
    while(j<=n){
        Y=0; W=v[j++].first;
        while(i<=m)Y+=getCheckValue(t[i].first,t[i].second,W,v),i++; i=1;
        ans=llabs(s-Y); 
        if(result>ans) result=ans;
    }
    cout<<result<<endl;
    return 0;
}
