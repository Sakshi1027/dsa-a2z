class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high)

        {
            int mid=(high+low)/2;
            if(nums[mid]==target)
             return mid;
            else if(target<=nums[mid])
            {
                high=mid-1;
            }
            else 
             low=mid+1;
            
        }
        
         return -1;
        
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        for(int i=0;i<m;i++)
        {
            if(search(matrix[i],target)!=-1)
             return true;
           
        }
        return false;

        
    }
};