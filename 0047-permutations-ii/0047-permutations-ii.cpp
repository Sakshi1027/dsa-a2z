class Solution {
public:
    void solve(vector<int>& nums,vector<int>& current,vector<vector<int>>& ans,vector<int>& visited)
    {
        if(current.size()==nums.size())
        {
            ans.push_back(current);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1] && !visited[i-1])
             continue;
            if(visited[i])
             continue;
            current.push_back(nums[i]);
            visited[i]=true;
            solve(nums,current,ans,visited);
            current.pop_back();
            visited[i]=false;
            
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> current;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> visited(nums.size(),false);
        solve(nums,current,ans,visited);
        return ans;
        
    }
};