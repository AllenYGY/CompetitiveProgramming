#include <iostream>
#include <vector>

using namespace std;

// 定义上、下、左、右四个方向的行列偏移
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vector<vector<bool> > visited;

// 检查一个位置是否在网格内
bool isValid(int r, int c, int rows, int cols)
{
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

void dfs(vector<vector<int> > &grid, int r, int c, int rows, int cols)
{
    if(isValid(r, c, rows, cols) == false || grid[r][c] == 0)
    { 
        return;
    }

    visited[rows][cols]=true;
    // 递归地访问上、下、左、右四个邻居位置
    for (int i = 0; i < 4; ++i)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        dfs(grid, nr, nc, rows, cols);
    }
}

// 主函数
int main()
{
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int> > grid(rows, vector<int>(cols));

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool> >(rows, vector<bool>(cols, false));

    // * 先遍历边框 
    for(int i=0; i< rows; ++i)
    {
        dfs(grid, i, 0, rows, cols);
        dfs(grid, i, cols-1, rows, cols);
    }

    for(int j=0; j < cols-1; ++j)
    {
        dfs(grid, 1, j, rows, cols);
        dfs(grid, rows-1, j, rows, cols);
    }

    // 计算飞地数量
    int numIslands = 0;

    // * 遍历剩余网格图
    // * 剩余部分即是 飞地
    for (int i = 1; i < rows-1; ++i)
    {
        for (int j = 1; j < cols-1; ++j)
        {
            if (grid[i][j] == 1 && !visited[i][j])
            {
                numIslands++;
            }
        }
    }
    cout << "Number of islands: " << numIslands << endl;
    return 0;
}

/*
4 4
0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0
*/

/* 
4 4
0 1 1 0
0 0 1 0
0 0 1 0
0 0 0 0
*/
