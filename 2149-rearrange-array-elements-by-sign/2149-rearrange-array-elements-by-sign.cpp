class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> pos;  // positives
        vector<int> neg;  // negatives
        
        // separate positives and negatives
        for(int x : nums) {
            if(x > 0)
                pos.push_back(x);  // ✅
            else
                neg.push_back(x);  // ✅
        }
        
        // place alternately — pos at even, neg at odd
        for(int i = 0; i < nums.size()/2; i++) {
            nums[2*i]   = pos[i];   // even index → positive
            nums[2*i+1] = neg[i];   // odd index  → negative
        }
        
        return nums;
    }
};