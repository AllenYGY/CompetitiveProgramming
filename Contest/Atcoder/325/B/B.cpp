#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int W[N+1][2];
    int V[N + 1];
    for (int i = 1; i <= N; i++)
    {
        cin >> W[i][0] >> W[i][1];
        V[i] = W[i][1];

    }
    int ans=-1;
    for (int i = 1; i <= N; ++i)
    {
        int record = V[i];
        int num = 0;
        for (int j = 1; j <= N; ++j)
        {
            if(W[j][1]-record>=9&&W[j][1]-record<18)
            {
                num+=W[j][0];
            }
        }
        if(num>ans) ans=num;
    }

    cout << ans<< endl;

    return 0;
}
