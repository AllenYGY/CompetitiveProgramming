#include <bits/stdc++.h>
#define int long long
using namespace std;

int matrix[810][810];
int md = 1000000007;
signed main()
{
    int N;
    cin >> N;
    bool up=true;
    bool down=true;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> matrix[i][j];
            if(i>j){
                if(matrix[i][j]!=0){
                    down=false;
                }
            }else if(i<j){
                if(matrix[i][j]!=0){
                    up=false;
                }
            }
        }
    }
    int ans = 1;
    if (up or down)
    {
        for (int i = 1; i <= N; i++)
        {
            ans *= matrix[i][i];
            ans %= (md);
        }
        ans %= (md);
        if (ans < 0)
        {
            ans += md;
        }
        cout << ans << endl;
    }
    else
    {
        cout << "Arknights!" << endl;
    }
}
