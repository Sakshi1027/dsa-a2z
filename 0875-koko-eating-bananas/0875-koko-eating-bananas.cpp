class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int low=1,high=*max_element(piles.begin(),piles.end());
       int result=high;
       while(low<=high)
       {
        int mid=(low+high)/2;
        long long hours=0;
        for(int p:piles)
         hours+=ceil((double)p/mid);
        if(hours<=h)
        {
         result=mid;
         high=mid-1;
        }
        else
         low=mid+1;
       }
       return result; 
    }
};