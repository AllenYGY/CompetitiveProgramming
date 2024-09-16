// #include<bits/stdc++.h>
#include<iostream>
// #include<vector>
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
 
signed main() {
    int N=read();
    int M=read();
    int v[N+1]={0};
    for(int i=0;i<M;i++){
        int n=read();
        char g;cin >> g;
        if(v[n]==0 and g=='M'){
            v[n]=1;
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
 
    return 0;
}