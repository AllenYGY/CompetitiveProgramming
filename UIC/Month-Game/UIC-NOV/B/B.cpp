#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
  int t = 0;
  cin >> t;
  int a, b, c;

  while (t--)
  {
    cin >> a >> b >> c;
    if (a + b > c)
    {
      cout << "No" << endl;
    }
    else
    {
      cout << "Yes" << endl;
    }
  }
  return 0;
}