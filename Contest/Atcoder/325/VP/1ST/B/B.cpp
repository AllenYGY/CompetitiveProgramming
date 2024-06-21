#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
  int m, n;
  cin >> m >> n;
  vector<vector<char>> A(m + 1, vector<char>(n + 1, 'X'));
  vector<vector<char>> B(m + 1, vector<char>(n + 1, 'X'));
  for (int i = 1; i < A.size(); ++i)
    for (int j = 1; j < A[i].size(); ++j)
      cin >> A[i][j];
  for (int i = 1; i < B.size(); ++i)
    for (int j = 1; j < B[i].size(); ++j)
      cin >> B[i][j];
  for (int i = 1; i < A.size(); ++i)
  {
    for (int j = 1; j < B.size(); ++j)
    {
    }
  }
  return 0;
}
bool check(vector<vector<char>> &A, vector<vector<char>> &B)
{
  for (int i = 1; i < A.size(); ++i)
  {
    for (int j = 1; j < A[i].size(); ++j)
    {
      if (A[i][j] != B[i][j])
      {
        return false;
      }
    }
  }
  return true;
}
