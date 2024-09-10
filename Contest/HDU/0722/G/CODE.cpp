#include<bits/stdc++.h>
#include<iostream>
#define int long long
#define endl '\n'
using namespace std;

void parseURL(const string& url) {
    regex urlRegex(R"((\w+):\/\/([a-zA-Z0-9\.-]+)\/([\w\-=\/]+)\/?)");
    smatch match;
    if (regex_match(url, match, urlRegex)) {
        string protocol = match[1];
        string networkLocation = match[2];
        string path = match[3];
        cout << protocol << endl;
        cout << networkLocation << endl;
        unordered_map<string, string> envVariables;
        regex pathRegex(R"((\w+)=([\w\-=]+)\/?)");
        auto pathBegin = sregex_iterator(path.begin(), path.end(), pathRegex);
        auto pathEnd = sregex_iterator();
        for (sregex_iterator i = pathBegin; i != pathEnd; ++i) {
            smatch match = *i;
            string key = match[1];
            string value = match[2];
            envVariables[key] = value;
            cout << key << " = " << value << endl;
        }
    } 
}

signed main() {
    int T;
    cin>>T;
    while(T--){
        string url;
        cin>>url;
        parseURL(url);
    }
    return 0;
}

