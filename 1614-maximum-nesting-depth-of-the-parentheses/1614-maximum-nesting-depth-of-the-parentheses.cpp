class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int level=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
             level++;
            cnt=max(level,cnt);
            if(s[i]==')')
             level--;
        }
        return cnt;
        
    }
};