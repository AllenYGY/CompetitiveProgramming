#include <iostream>
#include <vector>

using namespace std;

class Solution
{

private:
    int m, n;

public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int numIslands(vector<vector<int>> &grid)
    {

        this->m = grid.size();
        this->n = grid[0].size();

        int islands = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }

    void dfs(vector<vector<int>> &grid, int row, int col)
    {
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0)
        {
            return;
        }
        grid[row][col] = 0;
        for (auto &dir : dirs)
        {
            dfs(grid, row + dir[0], col + dir[1]);
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 1, 0, 0, 0},
                                {1, 1, 0, 0, 0},
                                {0, 0, 0, 1, 1},
                                {0, 0, 0, 1, 1}};
    cout << s.numIslands(grid) << endl;
    return 0;
}
