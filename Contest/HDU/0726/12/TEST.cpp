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
    int maxnum = 0, minnum = 0;
    int left= 1, right = left+2;
    while(right<n){
        minnum = min(a[0], a[left]);
        maxnum = max(a[0], a[left+2]);
        diff=maxnum-minnum;
        if(diff>D){
            left++;
            continue;
        }
        for(int i=left;i<left+3;i++){
            if(a[i]>=L){
                MorethanL--;
            }
            if(MorethanL<0){
                left++;
                MorethanL=tmp;
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