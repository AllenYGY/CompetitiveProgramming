#include <iostream>
#include <vector>

using namespace std;

// 定义上、下、左、右四个方向的行列偏移
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
// 计算岛屿数量
int numIslands = 0;
int boreder = 0;

// 检查一个位置是否在网格内
bool isValid(int r, int c, int rows, int cols)
{
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

// 检查一个位置是否在边框
bool isBorder(int r, int c, int rows, int cols)
{
    return r == 0 || r == rows - 1 || c == 0 || c == cols - 1;
}

// ! 判断封闭岛屿
// * 首先判断是否越界   --当且仅当越界时 ---- 不是封闭岛屿 --- 故返回 false
// * 其次判断是否为陆地 --为陆地时 ---- 仅证明该陆地连通，不能证明其实封闭岛屿 --- 故返回 true

// 深度优先搜索函数
bool dfs(vector<vector<int> > &grid, int r, int c, int rows, int cols)
{
    if(!isValid(r, c, rows, cols))
    {
        return false;
    }
    if (grid[r][c] != 0) {
        return true;
    }
    // 标记当前位置为已访问
    grid[r][c] = 1;

    bool ret1 = dfs(grid, r+ dr[0], c+ dc[0], rows, cols);
    bool ret2 = dfs(grid, r+ dr[1], c+ dc[1], rows, cols);
    bool ret3 = dfs(grid, r+ dr[2], c+ dc[2], rows, cols);
    bool ret4 = dfs(grid, r+ dr[3], c+ dc[3], rows, cols);
    return ret1 && ret2 && ret3 && ret4;
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

    // 遍历整个网格图
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (grid[i][j] == 0)
            {
                // 如果发现陆地，进行深度优先搜索
                if(dfs(grid, i, j, rows, cols))
                    ++numIslands;
            }
        }
    }

    cout << "Number of islands: " << numIslands << endl;

    return 0;
}

//* 0 陆地
//* 1 海洋

/*
5 8
1 1 1 1 1 1 1 0
1 0 0 0 0 1 1 0
1 0 1 0 1 1 1 0
1 0 0 0 0 1 0 1
1 1 1 1 1 1 1 0
*/

/*
3 5
0 1 1 0 0
1 0 0 1 0
0 1 1 1 0
*/