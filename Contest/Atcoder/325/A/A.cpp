#include<bits/stdc++.h>
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

signed main(){
    string s;
    string t;
    cin>>s;
    
    cout<<s<<" "<<"san"<<endl;
    return 0;
}