
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std; 


int read(){
    int x=0,f=1;
    char ch = getchar();
    while(ch<'0' || ch >'9'){
        if(ch=='-'){
            f=-1;
        }
        ch=getchar();
    }
    while (ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    
    return x*f;
    
}

void solve(){
    string s;
    cin>>s;
    string ans="";
    for(int i=0;i<s.size();){
        if(s[i]!='(' and s[i]!=')'){
            ans+=s[i];
        }
        if(s[i]=='('){
           int j=0;
            while (s[i++]!=')' and i<s.size())
            {
                j++;
            }
            ans+='@';
            continue;
        }
        i++;
    }
    cout<<ans<<endl;
}


signed main(){
    solve();
    return 0;
}