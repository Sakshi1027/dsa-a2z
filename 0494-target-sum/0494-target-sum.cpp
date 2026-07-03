class Solution {
public:
    int helper(vector<int>& nums,int target,int index,int sum)
    {
        if(index==nums.size())
         return(sum==target);
        int left=helper(nums,target,index+1,sum+nums[index]);
        int right=helper(nums,target,index+1,sum-nums[index]);
        return left+right;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums,target,0,0);
        
    }
};