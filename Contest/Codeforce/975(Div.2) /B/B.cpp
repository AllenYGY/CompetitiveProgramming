#include<bits/stdc++.h>
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



void solve(){
    int n = read(), q = read();
    vector<int> a(n), b(q);
    for(int i=0;i<n;i++) {
        a[i] = read();
    }
    for(int i=0;i<q;i++) b[i] = read();
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int key=(i+1)*(n-i-1);
        mp[key]+=a[i+1]-a[i]-1;
    }
    for(int i=0;i<n;i++){
        int key=i*(n-i-1)+n-1;
        mp[key]++;
    }
    for(int i=0;i<q;i++){
        cout<<mp[b[i]]<<" ";
    }
    cout<<endl;


}

signed main() {
    int T = read();
    while (T--) {
        solve();
    }
    return 0;
}