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
 
signed main() {
    int n = read();
    int a[n+2]={0};
    for (int i = 1; i < n+1; i++) {
        int tmp = read();
        a[i] = (a[i-1]+tmp)%360;
    }
    a[n+1]=360;
    sort(a+1,a+n+1);
    int ans = -1;
    for(int i=1; i<n+2; i++){
        ans=max(ans,a[i]-a[i-1]);
    }
    cout<<ans<<endl;
    return 0;
}
