#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<float> line(n);

    for (int i = 0; i<n;i++) {
        std::cin >> line[i];
    }

    std::vector<int> ascendingSequence(n, 1), descendingSequence(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (line[i] > line[j]) {
                ascendingSequence[i] = std::max(ascendingSequence[i], ascendingSequence[j] + 1);
            }
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (line[i] > line[j]) {
                descendingSequence[i] = std::max(descendingSequence[i], descendingSequence[j] + 1);
            }
        }
    }

    
    int ans = 1100;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            ans = std::min(ans, n - ascendingSequence[i] - descendingSequence[j]);
    }

    std::cout << ans << std::endl;

    return 0;
}