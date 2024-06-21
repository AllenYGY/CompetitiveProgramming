#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
  int T = 0;
  cin >> T;
  for (int i = 0; i < T; i++)
  {
    int size = 0;
    cin >> size;
    cout << size;
    int count0 = 0;
    int count1 = 0;
    string s;
    cin >> s;
    for (int i = 0; i < size; i++)
    {
      if (s[i] == '0')
      {
        count0++;
      }
      else
      {
        count1++;
      }
    }
    if (count0 == size || count1 == size)
    {
      cout << "Bob" << endl;
    }
    int min = count0 > count1 ? count1 : count0;
    int count = count0 + count1 - 2 * min;
    if (count % 2 == 0)
    {
      cout << "Bob" << endl;
    }
    else
    {
      cout << "Alice" << endl;
    }
  }
  return 0;
}