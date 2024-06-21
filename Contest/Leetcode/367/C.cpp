#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if(m.find(nums[i])!= m.end())
        }
        vector<int> v(2);
        for (int i = 0; i < nums.size()-indexDifference; i++)
        {
            if (m.find()!= m.end()){
                v[0]=i;
                v[1]=i+indexDifference;
                return v;
            }
        }
        v[0]=-1;
        v[1]=-1;
        return v;
    }
};