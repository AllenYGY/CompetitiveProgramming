
#include <bits/stdc++.h>
using namespace std;

bool isPalindromic(long long n) {
    string str = to_string(n);
    string rev = str;
    reverse(rev.begin(), rev.end());
    return str == rev;
}

int main() {
    long long N;
    cin >> N;
    long long ans = 0;
    for (long long i = 1; i * i * i <= N; i++){
        if (isPalindromic(i * i * i)) 
            ans = i * i * i;
    }
    cout << ans << endl;
    return 0;
}
