class Solution {
public:
    bool solve(int index,vector<int>& nums,vector<int>& sides,int target)
    {
        if(index==nums.size())
         return true;
        for(int i=0;i<sides.size();i++)
        {
            if(sides[i]+nums[index]<=target)
            {
                sides[i]+=nums[index];
                if(solve(index+1,nums,sides,target))
                 return true;
                sides[i]-=nums[index];
            }
            if(sides[i]==0)
             break;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        vector<int> sides(4,0);
        int sum=0;
        for(int i=0;i<matchsticks.size();i++)
        {
            sum+=matchsticks[i];
        }
        if(sum%4!=0)
         return false;
        int target=sum/4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        return solve(0,matchsticks,sides,target);

        
    }
};