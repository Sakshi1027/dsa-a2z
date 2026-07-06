class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int x:nums)
        {
            mp[x]++;
        }
        int max=0;
        int ans=-1;
        for(auto it:mp)
        {
            if(it.second>max)
            {
                max=it.second;
                ans=it.first;
            }
        }
        return ans;
    }
};