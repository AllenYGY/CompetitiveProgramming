#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

// 方向数组：上、右、下、左（顺时针）
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

// 输出地图
void printMap(const vector<pair<int, int>>& path) {
    // 找出地图边界
    int minX = INT_MAX, maxX = INT_MIN, minY = INT_MAX, maxY = INT_MIN;
    for (const auto& p : path) {
        minX = min(minX, p.first);
        maxX = max(maxX, p.first);
        minY = min(minY, p.second);
        maxY = max(maxY, p.second);
    }

    // 计算地图大小
    int rows = maxY - minY + 1;
    int cols = maxX - minX + 1;

    // 创建地图
    vector<vector<char>> grid(rows, vector<char>(cols, '.'));

    // 标记路径
    for (size_t i = 0; i < path.size(); ++i) {
        int x = path[i].first - minX;
        int y = path[i].second - minY;
        if (i == 0) {
            grid[y][x] = 'S'; // 起点
        } else if (i == path.size() - 1) {
            grid[y][x] = 'E'; // 终点
        } else {
            grid[y][x] = '*'; // 路径
        }
    }

    // 输出地图
    cout << "Map:\n";
    for (int i = rows - 1; i >= 0; --i) {
        for (int j = 0; j < cols; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        string commands;
        cin >> n >> commands;

        set<pair<int, int>> visited; // 记录访问过的坐标
        vector<pair<int, int>> path; // 保存路径

        int x = 0, y = 0; // 起始位置
        int dir = 0; // 起始方向（向上）

        visited.insert({x, y});
        path.push_back({x, y});
        bool overlap = false;
        
        for (char command : commands) {
            if (command == 'L') {
                dir = (dir + 3) % 4; // 左转
            } else if (command == 'R') {
                dir = (dir + 1) % 4; // 右转
            } else if (command == 'S') {
                x += dx[dir]; // 更新 x 坐标
                y += dy[dir]; // 更新 y 坐标
                
                // 检查是否重叠
                if (visited.count({x, y})) {
                    overlap = true;
                    path.push_back({x, y});
                    break; // 一旦发生重叠，可以立即停止
                } else {
                    visited.insert({x, y});
                    path.push_back({x, y});
                }
            }
        }

        // 输出路径
        printMap(path);

        // 输出结果
        if (overlap) {
            cout << "-1" << endl; // 存在重叠
        } else if (x == 0 && y == 0) {
            cout << "1" << endl; // 形成环
        } else {
            cout << "0" << endl; // 无重叠但不成环
        }
    }

    return 0;
}