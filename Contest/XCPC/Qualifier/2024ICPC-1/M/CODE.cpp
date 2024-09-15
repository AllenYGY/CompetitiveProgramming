// #include<bits/stdc++.h>
// #include<map>
#include<unordered_map>
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
    int n = read();
    unordered_map<string,int> mp;
    unordered_map<string,int> mp1;
    for(int i=0;i<n;i++){  
        string Team,pid,status;
        cin>>Team>>pid>>status;
        if(status=="accepted"){
            if(mp1[Team+pid]==0){
                mp1[Team+pid]=1;
                mp[pid]++;
            }
           
        }
    }
    char ans;
    int num=-1;
    for(auto i:mp){
        if(i.second>num){
            num=i.second;
            ans=i.first[0];
        }
        else if(i.second==num){
            if(i.first[0]<ans){
                ans=i.first[0];
            }
        }
    }
    cout<<ans<<endl;

}
 
signed main() {
    int T = read();
    while(T--){
        solve();
    }
    return 0;
}