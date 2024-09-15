// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
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
    int n = read(), m = read(), q = read();
    vector<int> v;
    for(int i=0; i<m; i++){
        int x = read();
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int David = read();
    
    int left= lower_bound(v.begin(), v.end(), David+1)-1-v.begin();
    int right=lower_bound(v.begin(), v.end(), David)-v.begin();
    left=max(0LL, left);
    right=min(m-1, right);
    if(v[left]==v[right]){
       if(v[left]>David){
            cout<<v[left]-1<<endl;
       }else{
            cout<<n-v[right]<<endl;
       }
       return;
    }
    cout<<(v[right]-v[left])/2<<endl;


}

signed main() {
    int T = read();
    while(T--){
        solve();
    }

    return 0;
}