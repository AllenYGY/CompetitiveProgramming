#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,k,ans;
int check(int p,int H[],int k,int n){
  int count=0,i=1,j=1;
  while(i<=n){
    if(H[i]>H[j]+p){
      count+=1,i++,j=i;
    }
    else i++;
  }
  return count;
}

int chk(int x,int H[]) {
    int pre = -1e9 - 20, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (H[i] - pre > x) {
            cnt ++;
            pre = H[i];
        }
    }
    return cnt;
}


signed main()
{
  cin>>n>>k;
  int H[n+1], i=1;
  while(i<=n) cin>>H[i++];
  sort(H+1,H+n+1);
  int l=0, r=H[n]-H[1],mid;
  while(l<=r){
    mid=(l+r)/2;
    if(chk(mid,H)<=k) ans=mid,r=mid-1;
    else l=mid+1;
  }
  cout<<ans;
  return 0;
}
// 5 3
// 8 4 3 6 9
