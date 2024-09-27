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

int getval(int a,int b,int c){
    return a*a+b*b+c*c+6*min(min(a,b),c);
}

void solve(){
    vector<int> val(3);
    val[0]=read(),val[1]=read(),val[2]=read();
    int d=read();
    sort(val.begin(),val.end());
    int a = val[0], b = val[1], c = val[2];

    int score_1=getval(a,b,c+d);
    int score_2=getval(a,b+d,c);
    int score_3=getval(a+d,b,c);
    cout<<max(max(score_1,score_2),score_3)<<endl;

}
 
signed main() {
    int T = read();
    while(T--){
        solve();
    }
    return 0;
}