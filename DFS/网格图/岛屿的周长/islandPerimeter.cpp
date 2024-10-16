// #include<iostream>
// #include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int dfs(int x,int y, vector<vector<int>> &grid,int n, int m)
    {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) 
        {
            cout<<"row: "<<x<<" col:"<<y<<endl;
            return 1;
        }
        if (grid[x][y]==2)
        {
            return 0;
        }
        grid[x][y]=2;
        int res=0;
        for(int i=0;i<4;i++)
        {
            int tx=x+dx[i];
            int ty=y+dy[i];
            res+=dfs(tx,ty,grid,n,m);
        }
        return res;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        int ans = 0;
        for(int i = 0; i<n; ++i)
        {
            for(int j=0;j<m; ++j)
            {
                if(grid[i][j]==1)
                {
                    ans+=dfs(i,j,grid,n,m); j=m; i=n;
                }
            }
        }
        return ans;
    }
};

// * 碰壁+1
// ! 每个格子都有四个方向，所以会重复  
int main(){
    Solution s;
    vector<vector<int> > grid = {{0,1,0,0},  // * 3                                                                                                                                                                 
                                 {1,1,1,0},  // * 6 
                                 {0,1,0,0},  // * 2
                                 {1,1,0,0}}; // * 5
    cout << s.islandPerimeter(grid) << endl;
    return 0;
}
