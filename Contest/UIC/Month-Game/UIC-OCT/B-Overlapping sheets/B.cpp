#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int a, b, c, d;
    int map[100][100];
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            map[i][j]=0;

    while (n--)
    {
        cin >> a >> b >> c >> d;
        for (int i = a; i < b; i++)
        {
            for (int j = c; j < d; j++)
            {
                map[i][j] = 1;
            }
        }
    }
    int count=0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if(map[i][j] == 1)
                count++;
        }
    }
    cout<<count;
    return 0;
}