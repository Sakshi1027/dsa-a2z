class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int cnt = 1, maxLen = 1;

        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i+1] == nums[i] + 1) {
                cnt++;
            }
            else if(nums[i+1] != nums[i]) {
                cnt = 1;
            }

            maxLen = max(maxLen, cnt);
        }

        return maxLen;
    }
};