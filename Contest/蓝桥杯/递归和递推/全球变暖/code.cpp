#include <iostream>
using namespace std;
char g[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N;
int dfs(int x, int y)
{
    if (g[x][y] == '.')
        return 0;
    if (g[x][y] == '*')
        return 1;
    g[x][y] = '*';
    int ans = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;
        if(dfs(nx, ny)==0){
            ans=0;
        }
    }
    return ans;
}

int main()
{
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++)
        cin >> g[i];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (g[i][j] == '#')
            {
                ans += dfs(i, j);
            }
        }
    }
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << g[i][j];
    //     }
    //     cout << endl;
    // }
    cout << ans;
    return 0;
}
