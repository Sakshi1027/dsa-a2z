class Solution {
public:
    int binarysearch(vector<int>& nums,int left,int right,int target)
    {
        if(left>right)
          return -1;
        int mid=(left+right)/2;
        if(nums[mid]==target)
         return mid;
        else if(nums[mid]<target)
         return binarysearch(nums,mid+1,right,target);
        else
         return binarysearch(nums,left,mid-1,target);
         
    }
    int search(vector<int>& nums, int target) {
        return binarysearch(nums,0,nums.size()-1,target);
        
    }
};