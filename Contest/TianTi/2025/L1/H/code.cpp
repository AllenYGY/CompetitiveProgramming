#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

vector<vector<int>> updateMe(vector<vector<int>> &meze,int min_val)
{
    int recI = 0;
    int recJ = 0;
    int col = meze[0].size();
    int row = meze.size();
    int max_val = min_val;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (max_val < meze[i][j])
            {
                max_val = meze[i][j];
                recI = i;
                recJ = j;
            }
        }
    }

    for (int i = recI, j = 0; j < col; j++)
    {
        meze[i][j] = min_val;
    }
    for (int j = recJ, i = 0; i < row; i++)
    {
        meze[i][j] = min_val;
    }
    return meze;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> me(n, vector<int>(m, 0));
    vector<int> vec;
    int min_val=INT64_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> me[i][j];
            // min_val=min(min_val,me[i][j]);
        }
    }
    // min_val-=1;
    // cout<<min_val<<endl;
    while (k--)
    {
        me = updateMe(me,min_val);
    }

    int lastcol=0;
    for (int i = 0,j=0; j < m; j++)
    {
        if(me[i][j]!=min_val) lastcol=j;
    }
    // cout<<lastcol<<endl;
    for (int i = 0; i < n; i++)
    {
        int flag=0;
        for (int j = 0; j < lastcol; j++)
        {
            if (me[i][j] !=  min_val)
            {
                flag=1;
                cout << me[i][j] << " ";
            }
        }
        if(flag) cout <<me[i][lastcol]<< endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}