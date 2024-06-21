#include<iostream>
#include<vector>
using namespace std;

class Solution {
    
private:
    int m, n;
    vector<vector<bool> > visited;
    int area=0;
public:
    vector<vector<int> > dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        this->visited = vector<vector<bool> >(m, vector<bool>(n, false));
        // * visited 记录 遍历过的点 说明是联通的
        cout<<area<<endl;

        area = 0;
        int maxarea=0;
        for (int i = 0; i < m ; i++) {
            for (int j = 0; j < n ; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    dfs(grid, i, j);
                    if(maxarea<area)
                        maxarea=area;
                    area = 0; 
                }
            }
        }
        return maxarea;
    }

    void dfs(const vector<vector<int> > & grid, int row, int col) {
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0 || visited[row][col]) {
            return;
        }
        visited[row][col] = true;
        area++;
        for (auto & dir : dirs) {
            dfs(grid, row + dir[0], col + dir[1]);
        }
    }
};

int main(){
    Solution s;
    vector<vector<int> > grid = {{0,1,0,0},
                                 {1,1,1,0},
                                 {0,1,0,0},
                                 {1,1,0,0}};
    cout << s.maxAreaOfIsland(grid) << endl;
    return 0;
}
