#include <iostream>
#include <unordered_map>

#define int long long
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
signed main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char a ,b,c,d;
        cin>>a>>b>>c>>d;
        unordered_map<char, int> m;
        m[a]++; m[b]++; m[c]++; m[d]++;
        if (m[a] == 3 || m[b] == 3 || m[c] == 3 || m[d] == 3)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        m.clear();
    }
    return 0;
}
