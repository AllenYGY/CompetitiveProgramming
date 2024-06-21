#include<iostream>
#include<cmath>
#include<string.h>
#include<vector>
using namespace std;
int n, sum;//n为序列个数sum为累计和
int panduan = 0;//用来判断是否可以结束
int a[11],book[11];
void dfs(int step)
{
	if (step == n+1) {
		//一波结束了,计算一下值是多少
		vector<int> dp(n+1);
		for (int i = 1;i <= n;i++)
		{
			dp[i] = a[i];
		}//复制
		for (int i = 1;i <= n - 1;i++)
		{
				for (int j = n;j > i;j--)
				{
					dp[j] = dp[j] + dp[j - 1];
				}
		}
		if (dp[n] == sum&&panduan==0)
		{
			for (int i = 1;i <= n;i++)
			{
				cout<<a[i]<<" ";//输出完
			}
			panduan = 1;//已经找到了，不要再输出了
		}
		return;
	}
		//放东西
		for (int i = 1;i <= n;i++)
		{
			if (book[i] == 0)
			{
				if (panduan == 1) return;
				//i还没用过
				a[step] = i;
				book[i] = 1;
				dfs(step + 1);
				book[i] = 0;//拿回来
			}
		}
		return;	
}
 
int main() {
	
	cin >> n;cin >> sum;
	dfs(1);
	return 0;
}

// 1 2 3 6
// 3 5 9
// 8 14
// 22