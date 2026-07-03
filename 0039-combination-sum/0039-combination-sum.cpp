class Solution {
public:
    void solve(vector<int>& nums,int index,int target,vector<int>& ds,vector<vector<int>>& ans)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        if(index==nums.size()||target<0)
         return;
        ds.push_back(nums[index]);
        solve(nums,index,target-nums[index],ds,ans);
        ds.pop_back();
        solve(nums,index+1,target,ds,ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
     solve(candidates,0,target,ds,ans);
     return ans;
        
    }
};