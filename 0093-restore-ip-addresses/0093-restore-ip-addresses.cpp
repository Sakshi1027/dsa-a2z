class Solution {
public:
    bool isValid(string s)
    {
        if(s.size()==0||s.size()>3)
         return false;
        if(s.size()>1 && s[0]=='0')
         return false;
        int num=stoi(s);
        if(num>255)
         return false;
        return true;
    }
    void solve(int index,string s,vector<string>& ds,vector<string>& ans)
    {
        if(index==s.size() && ds.size()==4)
        {   
            string ip=ds[0]+"."+ds[1]+"."+ds[2]+"."+ds[3];
            ans.push_back(ip);
            return;
        }
        if(index==s.size()||ds.size()>4)
         return;
        for(int i=index;i<min(index+3,(int)s.size());i++)
        {
            string part=s.substr(index,i-index+1);
            if(isValid(part))
        {
            ds.push_back(part);
            solve(i+1,s,ds,ans);
            ds.pop_back();
        }

        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ds;
        vector<string> ans;
        solve(0,s,ds,ans);
        return ans;
        
    }
};