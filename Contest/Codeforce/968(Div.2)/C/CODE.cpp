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

void check(){
    string s;
    cin>>s;
    pair<int,int> tmp;
    set<pair<int,int>> ans;
    int n = s.size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(s[i]==s[j]){
                // cout<<i+1<<" "<<j+1<<endl;
                ans.insert({i+1,j+1});
                continue;
            }
            for(int k=i;k<j;k++){
                if(s[k]!=s[k+1]){
                    if(s[k]!=s[i]){
                        // cout<<i+1<<" "<<j+1<<endl;
                        ans.insert({i+1,j+1});
                    }
                    if(s[k+1]!=s[j]){
                        // cout<<i+1<<" "<<j+1<<endl;
                        ans.insert({i+1,j+1});
                    }
                }
                
            }   
        }
    }
    cout<<ans.size()<<endl;
}

void solve(){
    int n = read();
    string s;
    cin>>s;
    unordered_map<char,int> mp;
    for(int i=0;i<n;i++){
        mp[s[i]]++;
    }
    vector<pair<char,int>> v;
    for(auto i:mp){
        v.push_back({i.first,i.second});
    }
    // sort(v.begin(),v.end(),[](pair<char,int> a,pair<char,int> b){
    //     return a.second>b.second;
    // });
    
    for(int i=0;i<v.size();i++){
        if(v[i].second>=2){
            cout<<v[i].first;
            v[i].second--;   
        }
    }
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].second;j++){
            cout<<v[i].first;
        }
    }
    cout<<endl;
    return ;   
}

signed main() {
    int T=read();
    while(T--){
        solve();
        // check();
    }
    return 0;
}
// 1
// 4
// 10
// 28
// 36

// 5
// 3
// cba
// 5
// fddde
// 6
// lerutt
// 8
// pppppppp
// 10
// sfdreeoocc

// 1
// 10
// coesfdrcoe

// 3
// cba
// 5
// dddfe
// 6
// tlerut
// 8
// pppppppp
// 10
// eocsfrdeoc


// 3
// fddde
// dddfe
// feddd