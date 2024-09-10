#include <iostream>
#include <vector>
#include <climits>

using namespace std;
vector<vector<int>> v(4, vector<int>(4, 0));
int Min = INT_MAX;

bool check()
{
    int c = v[0][0];
    for (auto row : v)
    {
        for (auto col : row)
        {
            if (col != c)
                return false;
        }
    }
    return true;
}

bool isvaild(int x, int y)
{
    if (x >= 0 && x < 4 && y >= 0 && y < 4)
        return true;
    else
        return false;
}

void change(int x, int y)
{
    v[x][y]=!v[x][y];
    if (x - 1 >= 0)
        v[x - 1][y] = !v[x - 1][y];
    if (y - 1 >= 0)
        v[x][y - 1] = !v[x][y - 1];
    if (x + 1 < 4)
        v[x + 1][y] = !v[x + 1][y];
    if (y + 1 < 4)
        v[x][y + 1] = !v[x][y + 1];
}

void dfs(int count, int k)
{
    int x, y;
    if (count == 16)
    {
        if (check())
            if (k < Min)
                Min = k;
        return;
    }
    else
    {
        x=count/4;
        y=count%4;
        dfs(count+1,k);
        change(x,y);
        dfs(count+1,k+1);
        change(x,y);
    }
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            char x;
            cin >> x;
            if (x == 'b')
                v[i][j] = 0;
            else
                v[i][j] = 1;
        }
    }
    dfs(0,0);
    if(Min==INT_MAX) cout<<"Impossible"<<endl;
    else cout<<Min<<endl;
    return 0;
}
 
/*
bwwb
bbwb
bwwb
bwww
*/