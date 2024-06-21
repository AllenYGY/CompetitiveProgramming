#include <iostream>
using namespace std;
char g[100][100];
int mx[4]={-1,0,1,0};
int my[4]={0,1,0,-1};
int n=30,m=60;
int dfs(int x,int y){
  if(g[x][y]=='0') return 0;
  g[x][y]='0';
  int ans = 1;
  for(int i=0;i<4;i++){
    int nx=x+mx[i],ny=y+my[i];
    if(nx<0||ny<0||nx>=n||ny>=m) continue;
    ans += dfs (nx,ny);
  }
  return ans;
}

int main()
{
  for(int i= 0;i<n;i++) cin>>g[i];
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(g[i][j]=='1'){
        ans=max(ans,dfs(i,j));
      }
    }
  }
  cout<<ans;
  return 0;
}