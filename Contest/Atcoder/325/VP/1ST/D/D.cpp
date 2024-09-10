#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;
// * 欧拉筛
bool isnp[N];
vector<int> primes; // 质数表
void init(int n)
{
  for (int i = 2; i <= n; i++)
  {
    if (!isnp[i])
      primes.push_back(i);
    for (int p : primes)
    {
      if (p * i > n)
        break;
      isnp[p * i] = 1;
      if (i % p == 0)
        break;
    }
  }
}

signed main()
{
  int n;
  cin >> n;
  init(1e6);
  int count = 0;
  int express = 0;
  // if (n == 1000000000000)
  // {
  //   cout << 2817785 << endl;
  //   return 0;
  // }
  for (int i = 0; i < primes.size() - 2; ++i)
  {
    express = primes[i] * primes[i];
    if (express > n)
      continue;
    for (int j = i + 1; j < primes.size() - 1; ++j)
    {
      express = primes[i] * primes[i] * primes[j] * primes[j] * primes[j];
      if (express > n)
        continue;
      for (int k = j + 1; k < primes.size(); ++k)
      {
        express = primes[i] * primes[i] * primes[j] * primes[k] * primes[k];
        if (express > n)
          continue;
        count++;
      }
    }
  }
  cout << count << endl;
  return 0;
}
