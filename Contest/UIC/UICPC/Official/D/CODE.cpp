#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool camp(pair<char, int> &a, pair<char, int> &b)
{
    if (a.second > b.second) return true;
    if(a.second==b.second){
        return a.first<b.first;
    }
    return false;
}

void solve()
{
    string s="";
    cin >> s;
    map<char, int> chmap;
    for (int i = 0; i < s.size(); i++)
    {
        if (int(s[i]) >= 'a' && int(s[i]) <= 'z')
             chmap[char(s[i] - 32)]+=1;
        else if(s[i]>='A' and s[i]<='Z') chmap[s[i]]+=1;

    }
    vector<pair<char, int>> chp(chmap.begin(), chmap.end());
    sort(chp.begin(), chp.end(), camp);
    for (int i = 0; i < chp.size(); i++)
    {
        cout << chp[i].first << " " << chp[i].second << endl;
    }
    return;
}

signed main()
{
    solve();
    return 0;
}