#include<bits/stdc++.h>

// #define int long long 
#define endl '\n'

using namespace std;
// (((2+3)*4)-(5/(6*7)))

void printstring(string s){
    for(int i=s.size()-1;i>=0;i--){
        cout<<s[i];
    }
    cout<<endl;
}

void solve(){
    string s;cin >>s;
    stack<char> sta;
    // cout<<s<<endl;
    for(int i=0;i<s.size();i+=1){
        while(s[i]!=')'){
            sta.push(s[i]);
            i++;
        }
        string res="";
        while(sta.top()!='('){
            res+=sta.top();
            // cout<<sta.top()<<endl;
            sta.pop();
        }
        // cout<<sta.top()<<endl;
        sta.pop();
        printstring(res);
    }
}

int main(){
    solve();
    return 0;
}