dp ={}

def L(nums,i):
    if i in dp:
        return dp[i]
    
    if(i==len(nums)-1):
        return 1;
    max_len=1

    for j in range(i+1,len(nums)):
        if(nums[i]<nums[j]):
            max_len = max(max_len,L(nums,j)+1)
    dp[i]=max_len

    return max_len
def lengthOfLIS(nums):
    return max(L(nums,i) for i in range(len(nums)))

nums=[369, 227, 114, 358, 613, 479, 35, 153, 244, 470, 376, 299, 443, 274, 209, 559, 365, 461, 266, 819, 489, 345, 588, 416, 425, 143, 272, 334, 845, 779, 925, 409, 300, 318, 371, 124, 257, 97, 409, 527, 945, 734, 518, 676, 706, 967, 907, 819, 901, 931, 993, 803, 40, 697, 473, 421, 755, 789, 854, 810, 147, 21, 335, 844, 488, 105, 162, 286, 957, 783, 907, 833, 290, 298, 949, 83, 760, 408, 131, 153, 76, 647, 833, 70, 329, 544, 847, 687, 210, 707, 33, 197, 582, 309, 847, 810, 871, 958, 257, 977]

print(lengthOfLIS(nums))

