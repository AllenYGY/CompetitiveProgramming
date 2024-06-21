#include <bits/stdc++.h>
#define int long long
using namespace std;
const int a = 998244353;
signed main()
{
  int N;
  cin >> N;
  if (N % a < 0)
  {
    cout << a + N % a;
  }
  else
    cout << N % a;
  return 0;
}