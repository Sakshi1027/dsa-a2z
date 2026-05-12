class Solution {
public:
    bool canShip(vector<int>& weights,int capacity,int days)
    {
        int daysNeeded=1;
        int currentLoad=0;
        for(int w:weights)
        {
            if(currentLoad+w>capacity)
            {
                daysNeeded++;
                currentLoad=0;
            }
            currentLoad+=w;
        }
        return daysNeeded<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int result=high;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(canShip(weights,mid,days))
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