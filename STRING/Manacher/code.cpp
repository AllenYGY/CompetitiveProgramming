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

string transform(string s) {
    string res = "#";
    for (int i = 0; i < s.size(); i++) {
        res += s[i];
        res += "#";
    }
    return res;
}

string transformBack(string s) {
    string res = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '#') {
            res += s[i];
        }
    }
    return res;
}

string manacher(string s) {
    string t = transform(s);
    string ans = "";
    vector<int> p(t.size(), 0);
    int mx = 0;
    for(int i = 0, c = 0, r = 0, len; i < t.size(); i++) {
        len = i < r ? min(r - i, p[2 * c - i]) : 1;
        while (i + len < t.size() && i - len >= 0 && t[i + len] == t[i - len]) {
            len++;
        }
        if (i + len > r) {
            r = i + len;
            c = i;
        }
        if(len > mx){
            mx = len;
            ans = t.substr(i - len + 1, 2 * len - 1); // 2 * len - 1 是原字符串的长度
        }
        p[i] = len;
    }
    ans = transformBack(ans);
    return ans;
}
 
signed main() {
 
    return 0;
}
