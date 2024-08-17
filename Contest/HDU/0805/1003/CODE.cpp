#include <bits/stdc++.h>
#include <iostream>
#define int long long
#define endl '\n'
using namespace std;

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

void write(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

// Directions: up, right, down, left (clockwise)
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

signed main()
{
    int T = read();
    while (T--)
    {
        int n = read();
        string commands;
        cin >> commands;

        set<pair<int, int>> visited;
        int x = 0, y = 0; // starting position
        int dir = 0;      // starting direction (upwards)
        // left = 3
        // right = 1
        // up = 0
        // down = 2
        visited.insert({x, y});
        bool overlap = false;

        for (int i = 0; i < commands.size(); i++)
        {
            char command = commands[i];
            if (command == 'L')
            {
                // cout << "dir: " << dir << endl;
                // cout<< x<< " "<< y<< endl;
                if (i >= 1 and commands[i - 1] != 'S')
                {
                    x += dx[dir];
                    y += dy[dir];
                    // Check for overlap
                    if (visited.count({x, y}))
                    {
                        overlap = true;
                    }
                    else
                    {
                        visited.insert({x, y});
                    }
                }
                dir = (dir + 3) % 4; // Turn left

            }
            else if (command == 'R')
            {
                // cout << "dir: " << dir << endl;
                // cout<< x<< " "<< y<< endl;
                if (i >= 1 and commands[i - 1] != 'S')
                {
                    x += dx[dir];
                    y += dy[dir];
                    // Check for overlap
                    if (visited.count({x, y}))
                    {
                        overlap = true;
                    }
                    else
                    {
                        visited.insert({x, y});
                    }
                }
                dir = (dir + 1) % 4; // Turn right

            }
            else if (command == 'S')
            {
                // cout << "dir: " << dir << endl;
                // cout<< x<< " "<< y<< endl;
                x += dx[dir];
                y += dy[dir];
                // Check for overlap
                if (visited.count({x, y}))
                {
                    overlap = true;
                }
                else
                {
                    visited.insert({x, y});
                }
            }
        }
        x+=dx[dir];
        y+=dy[dir];
        // cout << x << " " << y << endl;
        if (overlap)
        {
            cout << "-1" << endl;
        }
        else if (x == 0 and y == 0 and dir == 0)
        {
            cout << "1" << endl; // forms a loop
        }
        else
        {
            cout << "0" << endl; // no loop and no overlap
        }
    }

    return 0;
}