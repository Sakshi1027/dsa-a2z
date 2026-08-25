class Solution {
public:
    bool isPalindrome(string s) {
        string str;

        for(int i = 0; i < s.size(); i++) {
            if(isalnum(s[i])) {
                s[i] = tolower(s[i]);
                str.push_back(s[i]);
            }
        }

        string str2 = str;
        reverse(str2.begin(), str2.end());

        for(int i = 0; i < str.size(); i++) {
            if(str[i] != str2[i])
                return false;
        }

        return true;
    }
};