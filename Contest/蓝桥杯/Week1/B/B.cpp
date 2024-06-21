#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  int n, t;
  cin >> n >> t;
  for (int ti = 0; ti < t; ti += 1) {
    string s;
    cin >> s;
    int x = 1, y = 1;
    for (char c : s) {
      if (c == 'L') {
        y *= 2;
      } else {
        y = y * 2 + 1;
      }
      x *= 2;
    }
    cout << y - x + 1 << "\n";
  }
}