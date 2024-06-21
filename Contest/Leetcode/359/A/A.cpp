#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        char w[words.size()];
        for(int i=0;i<words.size();i++){
            w[i]=words[i][0];
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!=w[i])
                return false;
        }
        return true;
    }
};