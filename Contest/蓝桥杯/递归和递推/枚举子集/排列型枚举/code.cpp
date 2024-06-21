#include<iostream>

using namespace std;

const int N=20;

bool used[N];
int way[N];

int n;

void dfs(int u){//当前选了几个数
	if(u>n){//输出
		for(int i=1;i<=n;i++){
			cout<<way[i]<<" ";
		}
		puts("");
		return ;
	}
    // 挑一个数放进way数组
	for(int i=1;i<=n;i++){
		if(used[i]) continue;
		used[i]=true;
		way[u]=i;
		dfs(u+1);
		used[i]=false;     
	}
}

int main(){
	cin>>n;
	dfs(1);
	return 0;
}
