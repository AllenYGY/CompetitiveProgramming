#include <iostream>
// #define int long long;
using namespace std;

int main()
{
  int n, A, B;
  cin >> n >> A >> B;
  int sum = A + B;
  int temp = 0;
  int i = 1;
  while (n--)
  {
    cin >> temp;
    if (temp == sum)
    {
      break;
    }
    i++;
  }
  cout << i << endl;
  return 0;
}