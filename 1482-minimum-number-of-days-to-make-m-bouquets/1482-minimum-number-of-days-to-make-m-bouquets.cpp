class Solution {
public:
    bool canMake(vector<int>&bloomDay,int day,int m,int k)
    {
        int bouquets=0;
        int consecutive=0;
        for(int bloom:bloomDay)
        {
            if(bloom<=day)
            {
                consecutive++;
                if(consecutive==k)
                {
                    bouquets++;
                    consecutive=0;
                }
            }
            else 
             consecutive=0;
        }
        return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total=(long long)m*k;
        if(total>bloomDay.size())
         return -1;
        int low=1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int result=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(canMake(bloomDay,mid,m,k))
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