#include<bits/stdc++.h>
#include<iostream>
#define int long long
#define endl '\n'
using namespace std;
 
int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
 
void write(int x){
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
 

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
    return {a.first + b.first, a.second + b.second};
}

void solve(const vector<string>& instructions) {
    unordered_map<char, pair<int, int>> direction_map = {
        {'N', {0, 1}},
        {'E', {1, 0}},
        {'S', {0, -1}},
        {'W', {-1, 0}}
    };

    for (const auto& instruction : instructions) {
        pair<int, int> pos = {0, 0};
        vector<pair<int, int>> path = {{0, 0}};

        for (const char& move : instruction) {
            pos = pos + direction_map[move];
            path.push_back(pos);
        }

        int cross_product_sum = 0;
        int n = path.size();
        for (int i = 1; i < n - 1; ++i) {
            auto [x1, y1] = path[i - 1];
            auto [x2, y2] = path[i];
            auto [x3, y3] = path[i + 1];
            cross_product_sum += (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2);
        }

        if (cross_product_sum > 0) {
            cout << "CCW" << endl;
        } else {
            cout << "CW" << endl;
        }
    }
}
signed main() {
    int n=read();
    vector<string> instructions(n);
    for (int i = 0; i < n; ++i) {
        cin >> instructions[i];
    }

    solve(instructions);

    return 0;
}