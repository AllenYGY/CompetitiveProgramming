#include <bits/stdc++.h>

using namespace std;

int suduku[20][20];

bool checkrow(int row)
{
    int rec[20] = {0};
    for (int j = 0; j < 9; j++)
    {
        if (suduku[row][j] > 9 or suduku[row][j] < 0)
        {
            return false;
        }
        if (rec[suduku[row][j]] == 1)
        {
            return false;
        }
        else
        {
            rec[suduku[row][j]] = 1;
        }
    }
    return true;
}

bool checkcol(int col)
{
    int rec[20] = {0};
    for (int i = 0; i < 9; i++)
    {
        if (suduku[i][col] > 9 or suduku[i][col] < 0)
        {
            return false;
        }
        if (rec[suduku[i][col]] == 1)
        {
            return false;
        }
        else
        {
            rec[suduku[i][col]] = 1;
        }
    }
    return true;
}

bool checksquare(int row, int col)
{
    int rec[20] = {0};
    for (int i = row; i < row + 3; i++)
    {
        for (int j = col; j < col + 3; j++)
        {
            if (suduku[i][j] > 9 or suduku[i][j] < 0)
            {
                return false;
            }

            if (rec[suduku[i][j]] == 1)
            {
                return false;
            }
            else
            {
                rec[suduku[i][j]] = 1;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int flag = 1;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> suduku[i][j];
            }
        }
        for (int i = 0; i < 9; i++)
        {
            if (!checkrow(i) or !checkcol(i))
            {
                flag = 0;
                break;
            }
        }
        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                if (!checksquare(i, j))
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    return 0;
}