#include<bits/stdc++.h>
#include<iostream>
#define int long long
#define endl '\n'
using namespace std;


int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void write(int x){
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

int checkHammingcode(const string& data, const string& parity){
    int size = parity.size();
    vector<int> check(size, 0);

    for (int i = 0; i < data.size(); i++) {
        if (data[i] == '1') {
            int position = i + 1;  
            for (int j = 0; j < size; j++) {
                if (position & (1 << j)) {
                    check[j]++;
                }
            }
        }
    }

    for (int i = 0; i < size; i++) {
        if (parity[i] == '1') {
            check[i]++;
        }
    }

    int error_position = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (check[i] % 2 != 0) {
            error_position |= (1 << i);
        }
    }
    
    return error_position;
}

signed main() {
    int n = read();
    string s; 
    cin >> s;
    string data = s.substr(0, n);
    string parity = s.substr(n, s.size() - n - 1);
    int parity_check = s[s.size()-1] - '0';
    for (char bit : data) {
        if (bit == '1')
            parity_check^=1;
    }

    if (parity_check == 0) {
        cout << data << endl;
    } 
    else {
        int error_position = checkHammingcode(data, parity);

        if (error_position > 0 && error_position <= n) {
            data[error_position - 1] = (data[error_position - 1] == '0') ? '1' : '0';
        }

        cout << data << endl;
    }
    return 0;
}