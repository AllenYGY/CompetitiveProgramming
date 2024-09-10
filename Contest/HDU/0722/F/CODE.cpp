#include<bits/stdc++.h>
#include<iostream>
#define int long long
#define endl '\n'
using namespace std;

using Fraction = pair<long long, long long>;

int gcd(int a, int b) {
    while (b) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

Fraction addFractions(const Fraction& f1, const Fraction& f2) {
    long long numerator = f1.first * f2.second + f2.first * f1.second;
    long long denominator = f1.second * f2.second;
    long long g = gcd(numerator, denominator);
    return {numerator / g, denominator / g};
}

Fraction multiplyFraction(const Fraction& f, long long k) {
    long long numerator = f.first * k;
    long long denominator = f.second;
    long long g = gcd(numerator, denominator);
    return {numerator / g, denominator / g};
}

Fraction divideFraction(const Fraction& f, long long k) {
    long long denominator = f.second * k;
    long long g = gcd(f.first, denominator);
    return {f.first / g, denominator / g};
}

vector<vector<int>> adj;
vector<double> p;
vector<Fraction> dp;
vector<bool> visited;

Fraction dfs(int node) {
    if (visited[node]) return dp[node];
    visited[node] = true;

    double pi = p[node] / 15.0;
    double qi = 1 - pi;

    Fraction expectation = {1, pi * 15};
    long long q = 1 - (p[node] / 15);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            Fraction subExp = dfs(neighbor);
            Fraction added = multiplyFraction(subExp, qi);
            expectation = addFractions(expectation, added);
        }
    }

    dp[node] = expectation;
    return dp[node];
}

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        adj.assign(n + 1, vector<int>());
        p.assign(n + 1, 0);
        dp.assign(n + 1, {0, 1});
        visited.assign(n + 1, false);

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }

        Fraction result = dfs(1);

        // Output the result as the simplest fraction
        long long g = gcd(result.first, result.second);
        result.first /= g;
        result.second /= g;

        cout << result.first << "/" << result.second << endl;
    }

    return 0;
}