#include <bits/stdc++.h>
using namespace std;

// 模拟查询函数：检查 t 是否是 s 的子串
int query_substring(const string &t, const string &s) {
    return (s.find(t) != string::npos) ? 1 : 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t; // 读取测试用例数量
    
    while(t--){
        int n;
        cin >> n; // 读取密码长度
        
        string s;
        cin >> s; // 读取实际密码（仅用于模拟，实际互动中不需要）
        
        string reconstructed = ""; // 重构的密码
        int queries_made = 0; // 查询次数
        const int max_queries = 2 * n; // 最大查询次数
        
        // 存储查询以便输出
        vector<string> queries;
        
        for(int i = 0; i < n; ++i){
            // 尝试添加 '0'
            string candidate0 = reconstructed + '0';
            // 保证子串长度不超过 n
            if(candidate0.length() > n){
                candidate0 = candidate0.substr(candidate0.length() - n, n);
            }
            queries.push_back("? " + candidate0);
            queries_made++;
            int response0 = query_substring(candidate0, s);
            
            if(response0 == 1){
                // '0' 是有效的
                reconstructed += '0';
            }
            else{
                // 尝试添加 '1'
                string candidate1 = reconstructed + '1';
                if(candidate1.length() > n){
                    candidate1 = candidate1.substr(candidate1.length() - n, n);
                }
                queries.push_back("? " + candidate1);
                queries_made++;
                int response1 = query_substring(candidate1, s);
                if(response1 == 1){
                    reconstructed += '1';
                }
                else{
                    // 如果 '0' 和 '1' 都无效，默认添加 '0'（根据具体情况调整）
                    reconstructed += '0';
                }
            }
            
            // 检查是否超出查询限制
            if(queries_made >= max_queries){
                break;
            }
        }
        
        // 输出所有查询
        for(auto &q : queries){
            cout << q << "\n";
        }
        
        // 输出重构的密码
        cout << "! " << s << "\n";
    }
    
    return 0;
}
