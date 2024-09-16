// #include<bits/stdc++.h>/
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


template <typename T>
struct Presum{
    vector<T> a;
    int n;
    Presum(int n_=0){
       init(n_);
    }
    Presum(vector<T> &b){
       presum(b);
    }
    void presum(vector<T> &b){
        init(b.size()+1);
        for(int i=1;i<n;i++){
            a[i]=a[i-1]+b[i-1];
        }
    }
    void init(int n_) {
        n = n_;
        a.assign(n, T());
    }
    T sum(){
        for(int i=1;i<=n;i++){
            a[i]+=a[i-1];
        }
    }
    T get(int i){
        return a[i];
    }
    T getRange(int l,int r){
        return a[r]-a[l-1];
    }
    void add(int i, const T &v) {
        a[i]+=v;
    }
    void addRange(int l,int r,const T &v){
        add(l,v);
        add(r+1,-v);
    }
};

int get_index(int x,vector<int> &X, char dir){
    if(dir=='L'){
        return lower_bound(X.begin(),X.end(),x)-X.begin();
    }
    return lower_bound(X.begin(),X.end(),x+1)-1-X.begin();
}

vector<int> X,P;

signed main() {
    int N=read(); 
    for(int i=0;i<N;i++){
        int x=read();
        X.push_back(x);
    }
    for(int i=0;i<N;i++){
        int p=read();
        P.push_back(p); 
    }
    Presum<int> ps(P);

    int Q=read();
    while(Q--){
        int l=read(),r=read();
        int ans=0;
        l=get_index(l,X,'L');
        r=get_index(r,X,'R');
        // cout << l << " " << r << endl;
        ans=ps.getRange(l+1,r+1);
        cout << ans << endl;
    }
    return 0;
}