class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nums1(n);  // ✅ allocate size
        
        k = k % n;  // handle large 
        
        for(int i = 0; i < n; i++) {
            nums1[(i + k) % n] = nums[i];
        }
        
        nums = nums1;  // copy back
    }
};