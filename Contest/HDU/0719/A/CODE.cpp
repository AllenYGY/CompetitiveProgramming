#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn = 1e6+5;
const ull base = 131;
char a[maxn],b[maxn];
ull Hash[maxn],p[maxn];
int T;
ull get(int l,int r){
    return Hash[r]-Hash[l-1]*p[r-l+1];
}
int main(){
    scanf("%d",&T);
    p[0] = 1;
    for(int i = 1;i<maxn;i++) p[i] = p[i-1]*base;
    while(T--){
        scanf("%s%s",a+1,b+1);
        int n = strlen(a+1),m = strlen(b+1);
        unordered_set<ull> s;
        for(int i = 1;i<=n;i++){
            a[i+n] = a[i];
        }
        Hash[0] = 0;
        for(int i = 1;i<=2*n;i++){
            Hash[i] = Hash[i-1]*base+a[i];
            if(i>=n) s.insert(get(i-n+1,i));
        }
        Hash[0] = 0;
        int ans = 0;
        for(int i = 1;i<=m;i++){
            Hash[i] = Hash[i-1]*base+b[i];
            if(i>=n && s.count(get(i-n+1,i))) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}