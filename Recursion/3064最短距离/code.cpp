#include <bits/stdc++.h>
#include <iostream>
#define int long long
#define endl '\n'

using namespace std;

int n, m, b, s, a[100005], x[100005], y[100005];

int manhattandist(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}


int dist(int i, int j){
    return manhattandist(x[i], y[i], x[j], y[j]);
}


signed main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
        if (i > 1)
            a[i] = dist(i, i - 1); 
        s += a[i];                
    }
    m = s;
    for (int i = 2; i <= n - 1; i++){
        b = s - a[i] - a[i + 1] + dist(i - 1, i + 1);
        m = min(m, b); 
    }
    cout << m << endl;
    return 0;
}
