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
            Suma++;
            Sumb+=v[l].second;
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
    vector <int> cpy(n+1,0);
    while(i<=n) v[i].first = cpy[i] = read(), v[i].second = read(),i++; i=1;
    while(i<=m) t[i].first = read(), t[i].second = read(),i++; i=1;
    int result=1e18, ans=0, W = 0, Y;
    sort(cpy.begin(),cpy.end());
    int left=1,right=n,mid;
    while(left<=right){
        Y=0; 
        mid=(left+right)/2; W=cpy[mid];
        while(i<=m)Y+=getCheckValue(t[i].first,t[i].second,W,v),i++; i=1;
        if(Y>=s) left=mid+1;
        else if(Y<s) right=mid-1;
        ans=llabs(s-Y); if(result>ans) result=ans;
    }
    cout<<result<<endl;
    return 0;
}

