#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int>v(2);
        for(int i=0;i<nums.size()-1;++i){
            for(int j=0;j<nums.size()-1;++j){
                if(abs(nums[j]-nums[i])>=valueDifference && (abs(j-i)>=indexDifference)) {
                    v[0]=i,v[1]=j;return v;
                }
            }
        }
        return v;
    }
};