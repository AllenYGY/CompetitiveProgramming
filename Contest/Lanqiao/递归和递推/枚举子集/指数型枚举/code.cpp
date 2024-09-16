#include<iostream>
using namespace std;

const int N=20;
bool st[N]={false}; //记录每个元素状态 选或不选
int n;

void dfs(int u){ //u 为当前状态
	if(u>n){ //Base Case
		for(int i=1;i<=n;i++){
			if(st[i]) cout<<i<<" ";
		}
		puts("");
		return ;
	}
	st[u]=false;// 不选择当前元素
		dfs(u+1);
	st[u]=true; // 选择当前元素
		dfs(u+1);
}

int main(){
	cin>>n;
	dfs(1);
	return 0;
}