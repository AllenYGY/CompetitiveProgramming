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

double dis(pair<int,int> a, pair<int,int> b){
    // 保留小数点后九位
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));  

}
 
signed main() {
    int n = read();
    pair<int,int> p[4];
    p[0].first=read(),p[0].second=read();
    p[1].first=p[0].first,p[3].second=p[0].second;
    p[2].first=read(),p[2].second=read();
    p[3].first=p[2].first, p[1].second=p[2].second;
    pair<int,int> pos[n];
    for(int i=0;i<n;i++){
        pos[i].first=read(),pos[i].second=read();
    }
    double res=INFINITY;
    int ans=0;
    double val=0.0;
    for(int i=0;i<n;i++){
        if((pos[i].first>=p[0].first && pos[i].first<=p[2].first) ) {
            val= min(abs(pos[i].second-p[0].second),abs(pos[i].second-p[2].second));
            cout << fixed << setprecision(9)<<val<<" ";
        }        
        else if(pos[i].second>=p[0].second && pos[i].second<=p[2].second){
            val= min(abs(pos[i].first-p[0].first),abs(pos[i].first-p[2].first));
            cout << fixed << setprecision(9)<<val<<" ";
        }
        else{
            val = min(min(dis(pos[i],p[0]),dis(pos[i],p[1])),min(dis(pos[i],p[2]),dis(pos[i],p[3]))); 
            cout << fixed << setprecision(9)<<val<<" ";
        }
        if (val<res){
            res=val;
            ans=i+1;
        }
    }
    cout<<endl<<ans<<endl;
    return 0;
}