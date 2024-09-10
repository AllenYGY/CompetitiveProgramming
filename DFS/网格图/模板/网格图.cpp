#include <iostream>
#include <vector>

using namespace std;

// 定义上、下、左、右四个方向的行列偏移
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// 检查一个位置是否在网格内
bool isValid(int r, int c, int rows, int cols)
{
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

// 深度优先搜索函数
void dfs(vector<vector<int> > &grid, int r, int c, int rows, int cols)
{
    // 检查当前位置是否在网格内，以及是否已经访问过
    if (!isValid(r, c, rows, cols) || grid[r][c] == 0)
    {
        return;
    }

    // 标记当前位置为已访问
    grid[r][c] = 0;

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

    // cout << "" << rows << " " << cols << endl;

    vector<vector<int> > grid(rows, vector<int>(cols));

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> grid[i][j];
        }
    }

    cout << "Load succussfully!" << endl;

    // 计算岛屿数量
    int numIslands = 0;

    // 遍历整个网格图
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (grid[i][j] == 1)
            {
                // 如果发现陆地，进行深度优先搜索
                dfs(grid, i, j, rows, cols);
                ++numIslands;
            }
        }
    }

    cout << "Number of islands: " << numIslands << endl;

    return 0;
}

/* 5 5
1 1 0 0 0
1 1 0 0 1
0 0 0 1 1
0 0 0 0 0
1 0 1 0 1
*/

/*
8 8
1 1 0 0 1 1 1 1
1 1 0 0 1 1 1 1
0 0 0 1 1 0 0 0
0 0 0 1 1 0 0 0
1 1 1 1 1 0 0 0
1 1 1 1 1 0 0 0
*/

/*
8 8
0 0 0 0 0 0 0 0
0 1 0 0 1 1 1 0
0 0 0 1 1 0 0 0
0 0 0 1 1 0 0 0
0 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0
*/

// 4 4
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0

// 3 4
// 1 1 1 1
// 1 1 1 1
// 0 0 0 0
