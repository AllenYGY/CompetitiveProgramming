#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    long long int N, D, P;
    cin >> N >> D >> P;

    vector<long long int> v(N + 1);
    long long int sum = 0;

    for (long long int i = 1; i <= N; i++) {
        cin >> v[i];
        sum += v[i];
    }

    sort(v.begin() + 1, v.end(), greater<long long int>());

    long long int last = 0, count = 1, ans = sum;

    for (long long int k = 1; k <= (N + D - 1) / D; k++) {
        for (long long int i = last + 1; i <= min(last + D, N); i++)
            sum -= v[i];

        ans = min(ans, count * P + sum);
        count++;
        last = last + D;
    }

    cout << ans << endl;
    return 0;
}
