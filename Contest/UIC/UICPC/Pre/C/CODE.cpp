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
 

int max_coins(int n, int m, const vector<int>& positions) {
    vector<int> sorted_positions = positions;
    sort(sorted_positions.begin(), sorted_positions.end());
    int max_count = 0;
    int start = 0;
    for (int end = 0; end < n; ++end) {
        while (sorted_positions[end] - sorted_positions[start] > m) {
            ++start;
        }
        int current_count = end - start + 1;
        max_count =max(max_count, current_count);
    }

    return max_count;
}

 
signed main() {
    int n=read(), m=read();
    vector<int> positions(n);
    for (int i = 0; i < n; ++i) {
        positions[i]=read();
    }

    int result = max_coins(n, m-1, positions);
    cout << result << endl;

    return 0;
}


