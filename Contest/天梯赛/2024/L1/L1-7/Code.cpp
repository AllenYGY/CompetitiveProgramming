#include <bits/stdc++.h>

using namespace std;

long long getdigit(long long num)
{
    long long ans = 1;
    while (num != 0)
    {
        ans *= num % 10;
        num /= 10;
    }
    return ans;
}

int getans(long long num)
{
    int count = 0;
    while (1)
    {
        count++;
        num = getdigit(num);
        if (num / 10 == 0)
        {
            break;
        }
    }
    return count;
}

int main()
{
    long long left, right;
    cin >> left >> right;
    vector<long long> res;
    int ans = -1;
    for (long long i = left; i <= right; i++)
    {
        int new_ans = getans(i);
        if (ans < new_ans)
        {
            ans = new_ans;
            res.clear();
            res.push_back(i);
        }
        else if (ans == new_ans)
        {
            res.push_back(i);
        }
    }
    cout << ans << endl;

    for (long long i = 0; i < res.size(); i++)
    {
        if (i < res.size() - 1)
            cout << res[i] << " ";
        else
        {
            cout << res[i];
        }
    }

    return 0;
}