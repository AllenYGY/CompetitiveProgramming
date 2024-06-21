#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution
{
public:
    int minimumSum(int n, int k)
    {
        int sum = 0, nums[1000], i = 1;
        while (i <= 1000)
            nums[i] = i++;
        i = 0;
        for (int j = 1; i < n; j++)
        {
            if (nums[j] != 0)
            {
                sum += nums[j];
                if(k-j>0) nums[k - j] = 0;
                i++;
            }
        }
        return sum;
    }
};