// #include<bits/stdc++.h>
// #include<iostream>
// #define int long long
// #define endl '\n'
// using namespace std;
 
// int read(){
//     int x = 0, f = 1;
//     char ch = getchar();
//     while (ch < '0' || ch > '9'){
//         if (ch == '-')
//             f = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9')
//         x = x * 10 + ch - '0', ch = getchar();
//     return x * f;
// }
 
// void write(int x){
//     if (x < 0)
//         putchar('-'), x = -x;
//     if (x > 9)
//         write(x / 10);
//     putchar(x % 10 + '0');
// }

// template <typename T>
// struct Presum{
//     vector<T> a;
//     int n;
    
//     Presum(int n_=0){
//         init(n_);
//     }
    
//     Presum(vector<T> &b){
//         presum(b);
//     }
    
//     void presum(vector<T> &b){
//         init(b.size()+1);
//         for(int i=1;i<n;i++){
//             a[i]=a[i-1]+b[i-1];
//         }
//     }
    
//     void init(int n_) {
//         n = n_;
//         a.assign(n, T{});
//     }
    
//     T sum(){
//         for(int i=1;i<=n;i++){
//             a[i]+=a[i-1];
//         }
//     }
    
//     T get(int i){
//         return a[i];
//     }
    
//     T getRange(int l,int r){
//         return a[r]-a[l-1];
//     }
    
//     void add(int i, const T &v) {
//         a[i]+=v;
//     }
    
//     void addRange(int l,int r,const T &v){
//         add(l,v);
//         add(r+1,-v);
//     }
// };

// inline int qpow(int a, int n, int p)
// {
//     int ans = 1;
//     while (n)
//     {
//         if (n & 1)
//             ans = ans % p * a % p;
//         a = a % p * a % p;
//         n >>= 1;
//     }
//     return ans;
// }

// const int MOD = 1e9+7;

// signed main() {
//     int n = read();
//     vector<int> a(n);
//     int s=1;
//     for (int i = 0; i < n; i++) {
//         a[i]=read();
//         s*=(a[i]%MOD);
//     }
//     vector<int> b(n);
//     for(int i=0;i<n;i++){
//         b[i]=qpow(a[i], MOD-2,MOD);
//     }
//     Presum<int> p(a);

//     for(int i=0;i<n;i++){
//         int val1=p.getRange(1,i)-p.getRange(i+2,n);
//         int val2 = ((b[i]%MOD)*s)%MOD;
//         cout<<val1<<" "<<val2<<endl;
//     }
//     return 0;
// }

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

int qpow(int a, int n, int p)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans = ans % p * a % p;
        a = a % p * a % p;
        n >>= 1;
    }
    return ans;
}

const int MOD = 1e9+7;



vector<int> initprefixSum(vector<int>a) {
    vector<int> presum(a.size() + 1, 0);
    for (int i = 1; i <= a.size(); i++) {
        presum[i] = presum[i - 1] + a[i - 1];
    }
    return presum;
}

int getRange(const vector<int> &a, int l, int r) {
    return a[r] - a[l - 1];
}

signed main() {
    int n = read();
    vector<int> a(n);
    int s = 1;
    
    for (int i = 0; i < n; i++) {
        a[i] = read();
        s = (s * (a[i] % MOD)) % MOD;
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = qpow(a[i], MOD - 2, MOD);
    }

    vector<int> prefixSum = initprefixSum(a);

    for (int i = 0; i < n; i++) {
        int val1 = getRange(prefixSum, 1, i) - getRange(prefixSum, i + 2, n);
        int val2 = ((b[i] % MOD) * s) % MOD;
        cout << val1 << " " << val2 << endl;
    }
    
    return 0;
}