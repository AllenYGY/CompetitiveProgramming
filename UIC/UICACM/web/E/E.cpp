#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
  int H, W;
  cin >> H >> W;
  char grid[H + 1][W + 1];
  int vis[H + 1][W + 1];
  memset(vis, 0, sizeof(vis)); // 将所有元素设置为0
  for (int i = 1; i < H + 1; i++)
  {
    for (int j = 1; j < W + 1; j++)
    {
      cin >> grid[i][j];
    }
  }
  int i = 1, j = 1;
  while (vis[i][j] == 0)
  {
    // cout<<"1111"<<endl;
    vis[i][j] = 1;
    switch (grid[i][j])
    {
    case 'U':
    {
      if (i != 1)
        i--;
      else
      {
        cout << i << " " << j << endl;
        return 0;
      }
      break;
    }
    case 'D':
    {
      if (i != H)
        i++;
      else
      {
        cout << i << " " << j << endl;
        return 0;
      }
      break;
    }
    case 'L':
    {
      if (j != 1)
        j--;
      else
      {
        cout << i << " " << j << endl;
        return 0;
      }
      break;
    }
    case 'R':
    {
      if (j != W)
        j++;
      else
      {
        cout << i << " " << j << endl;
        return 0;
      }
      break;
    }
    }
  }
  cout << -1 << endl;
  return 0;
}