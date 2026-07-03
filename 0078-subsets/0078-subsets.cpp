class Solution {
public:
    void solve(int index,vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans)
    {
        if(index==nums.size())
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
        solve(index+1,nums,ds,ans);
        ds.pop_back();
        solve(index+1,nums,ds,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        solve(0,nums,ds,ans);
        return ans;
        
    }
};