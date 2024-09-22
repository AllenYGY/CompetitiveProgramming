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
 
void solve(){
       
}
 
signed main() {
    int n = read();
    unordered_map<string, pair<int,int>> mp;
    for(int i=0;i<n;i++){
        string s;
        cin>>s; 
        char ch ;
        cin>>ch;
        if(ch == 'F') mp[s].first++;
        else mp[s].second++;
    }
    int ans = 0;
    for(auto i:mp){
        if (i.second.first >= 1 and i.second.second >= 1) {
            ans+=(min(i.second.first,i.second.second));
        }
    }
    cout<<ans<<endl;
    return 0;
}