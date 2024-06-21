#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
  int t = 0;
  cin >> t;
  while (t--)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int temp1 = a + b;
    int temp2 = c + d;
    if (a == c && b == d)
    {
      cout << 0 << endl;
    }
    else if (temp1 % 2 == temp2 % 2)
    {
      cout << 2 << endl;
    }
    else if (temp1 % 2 != temp2 % 2)
    {
      cout << 1 << endl;
    }
  }

  return 0;
}