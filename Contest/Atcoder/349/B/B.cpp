#include <bits/stdc++.h>

using namespace std;

bool is_good_string(string s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    unordered_map<int, int> freq_of_freq;
    for (const auto& pair : freq) {
        freq_of_freq[pair.second]++;
    }

    for (const auto& pair : freq_of_freq) {
        if (pair.second != 0 && pair.second != 2) {
            return false;
        }
    }

    return true;
}

int main() {

    string s;
    cin>>s;
    cout<<(is_good_string(s) ? "Yes" : "No")<<endl;

    return 0;
}
