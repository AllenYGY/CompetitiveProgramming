#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;

signed main()
{
    int N, D, P;
    cin >> N >> D >> P;
    vector<int> v(N);
    
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    
    sort(v.begin(), v.end(), greater<int>());

    int result = LLONG_MAX;
    int times = 0;

    for (int i = 0; i < N; i += D)
    {
        int sum = 0;
        for (int j = i; j < min(i + D, N); ++j)
            sum += v[j];

        result = min(result, times * P + sum);
        ++times;
    }

    cout << result << endl;

    return 0;
}
