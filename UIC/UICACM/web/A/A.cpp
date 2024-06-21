#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
  vector<char> c;
  char che;
  while (cin >> che && che != '\n')
  {
    c.push_back(che);
  }
  int size = c.size();

  cout << c[size / 2];
  return 0;
}