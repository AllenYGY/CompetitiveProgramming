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

signed main() {
    int n=read(), m=read();
    unordered_map<string, int> rank1;
    unordered_map<string, int> rank2;
    int r = 1;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (rank1.count(s) == 0) {
            rank1[s] = r;
            r++;
        }
    }
    r = 1;
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        if (rank2.count(s) == 0 ) {
            if(rank1.count(s)<r)
                rank2[s] = r;
            r++;
        }
    }

    vector<pair<string, int>> rank1_vector(rank1.begin(), rank1.end());
    vector<pair<string, int>> rank2_vector(rank2.begin(), rank2.end());

    sort(rank1_vector.begin(), rank1_vector.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second;  
    });

    sort(rank2_vector.begin(), rank2_vector.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second; 
    });

    vector<string> ans;
    set<string> unique_ans;  
    int R1 = rank1.size(), R2 = rank2.size();
    int i = 0;
    unordered_map<string,int> final;
    while (i < R1 or i < R2) {
        if(i<R1){
            string s=rank1_vector[i].first;
            if(final.count(s)==0)
                ans.push_back(rank1_vector[i].first);
            final[s]=1;
        }
        if(i<R2){
            string s=rank2_vector[i].first;
            if(final.count(s)==0)
                ans.push_back(rank2_vector[i].first);  
            final[s]=1;
        }
        i++;
    }

    for (const auto& str : ans) {
        cout << str << endl;
    }


    return 0;
}