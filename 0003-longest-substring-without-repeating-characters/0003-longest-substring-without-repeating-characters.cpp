class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int cnt=0;
        unordered_set<char> mp;
        for(int right=0;right<s.size();right++)
        {
           
                while(mp.count(s[right]))
                {
                  mp.erase(s[left]);
                  left++;
                }
            
             mp.insert(s[right]);
             cnt=max(cnt,right-left+1);
        }
        return cnt;
    }
};