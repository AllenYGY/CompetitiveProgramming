#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
  int t = 0;
  cin >> t;
  while (t--)
  {
    int size;
    cin >> size;
    int B[size];
    int check = 0;
    for (int i = 0; i < size; i++)
      cin >> B[i];
    for (int i = 0; i < size - 1; i++)
    {
      if (B[i] % B[i + 1] != 0)
      {
        cout << -1 << endl;
        check = 1;
        break;
      }
    }
    if (check == 0)
    {
      for (int i = 0; i < size; i++)
      {
        cout << B[i] << " ";
      }
    }
  }
  return 0;
}
