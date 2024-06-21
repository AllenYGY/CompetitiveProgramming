#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;
int h[N];
int n, k;

int chk(int x) {
    int pre = -1e9 - 20, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (h[i] - pre > x) {
            cnt ++;
            pre = h[i];
        }
    }
    return cnt;
}

void sol() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    sort(h + 1, h + n + 1);
    int l = 0, r = h[n] - h[1], mid, ans = r;
    while (l <= r) {
        mid = (l + r) / 2;
        if (chk(mid) <= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}

int main() {

    int T = 1;
    while (T--) {
        sol();
    }
    exit(0);
}