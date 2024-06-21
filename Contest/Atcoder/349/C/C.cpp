
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    string t;
    cin>>s>>t;
    s.append("x");
    for (int i = 0; i < t.size(); i++)
    {
        t[i]=tolower(t[i]);
    }
    int j=0;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]==t[j]){
            j++;
        }
        if(j==t.size()){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}