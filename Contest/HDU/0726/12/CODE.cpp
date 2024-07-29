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

bool checkSubarray(vector<int>& arr, int r, int l, int L, int num) {
    if (r < l || (r - l + 1) < 4) {
        return false;
    }
    for (int i = l; i <= r - 3; ++i) {
        vector<int> subarray(arr.begin() + i, arr.begin() + i + 4);
        if (find(subarray.begin(), subarray.end(), num) == subarray.end()) {
            continue; 
        }
        int count_ge_L = 0;
        for (int x : subarray) {
            if (x >= L) {
                ++count_ge_L;
            }
        }
        if (count_ge_L <= 2) {
            return true;
        }
    }
    return false;
}

void solve() {
    int n, L, D;
    n = read(); L = read(); D = read();
    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        a[i] = read();
        if (a[i] >= L) {
            cnt++;
        }
    }
    if (cnt >= n - 2) {
        cout << "No" << endl;
        return;
    }
    int num = a[0];
    sort(a.begin(), a.end());
    // 找到 a[0] 的位置
    int pos = lower_bound(a.begin(), a.end(), num) - a.begin();
    // 使用双指针
    for(int i = 0; i<n-3; i++){
        if(a[i]==num){
            continue;
        }
        if(a[i+3]-a[i]<=D){
            cout<<"Yes"<<endl;
            return;
        }

    }
    
}


signed main() {
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

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
 
void cnmwmh(){
    int n, L, D; 
    n=read(); L=read(); D=read();
    vector<int> a(n);
    int cnt = 0;
    for(int i=0; i<n; i++){
        a[i]=read();
        if(a[i]>=L){
            cnt++;
        }
    }
    if(cnt>=n-2) {
        cout<<"No"<<endl;
        return;
    }
    sort(a.begin()+1, a.end());
    int MorethanL = 2;
    if(a[0]>=L){
        MorethanL--;
    }
    int tmp=MorethanL;
    int diff = 0;
    int maxnum = 0;
    int minnum = 0;
    for(int i=1; i<n-3; i++){
        maxnum = max(a[0], a[i+2]);
        minnum = min(a[0], a[i]);
        diff=maxnum-minnum;
        if(diff>D) continue;
        for(int j=i;j<3;j++){
            if(a[j]>=L){
                MorethanL--;
            }
            if(MorethanL<0){
                break;
            }
        }
        if(MorethanL>=0){
            cout<<"Yes"<<endl;
            return;
        }
        MorethanL=tmp;
    }
    cout<<"No"<<endl;
    return;
}

signed main() {
    int T;
    cin>>T;
    while(T--){
        cnmwmh();
    }
    return 0;
}