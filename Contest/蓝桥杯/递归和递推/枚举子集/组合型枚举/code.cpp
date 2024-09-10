#include<iostream>

using namespace std;

const int N=30;
bool used[N];
int way[N];

int n;
int m;

void dfs(int u,int cnt){
	if(cnt==m){
		for(int i=1;i<=m;i++){
			cout<<way[i]<<" ";
		}
		puts("");
		return ;
	}
	for(int i=1;i<=n;i++){
        if(way[u-1]<i && !used[i]){
            used[i]=true;
		    way[u]=i;
    		dfs(u+1,cnt+1);
	    	used[i]=false;
        }

	}
}

int main(){
	cin>>n>>m;
	dfs(1,0);
	return 0;
}