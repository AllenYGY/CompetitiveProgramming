// nibuhuijuedezhegezhenshizifuchuantiba
// -1 -2 -3 -4 -5 -6 -7 -8 -9 -10 -11 -12 -13 13 12 11 10 9 8 7 6 5 4 3 2 1

#include<bits/stdc++.h>

// #define int long long 
#define endl '\n'

using namespace std;

int main(){
    string s; cin>>s;
    unordered_map<char,int>score;
    unordered_map<char,int>cnt;
    int len=s.length();
    for (int i=0;i<26;i++){
        cin>>score['a'+ char(i)];
    }
    int ans=0;
    for(int i=0;i<len;i++){
        ans+=(score[s[i]]);
        cnt[s[i]]+=1;
    }
    for(int i=0;i<25;i++){
        cout<<cnt['a'+char(i)]<<" ";
    }
    cout<<cnt['z']<<endl;
    cout<<ans<<endl;
    return 0;
}