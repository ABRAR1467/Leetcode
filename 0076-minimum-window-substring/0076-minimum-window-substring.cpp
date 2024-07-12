class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        int l=0,r=0;
        int res = INT_MAX;
        if(t.size()>s.size())return "";
        for(int i=0;i<t.size();i++)mp1[t[i]]++;
        int required = mp1.size();
        int formed = 0;
        int x = 0,y = 0;
        while(r<s.size())
        {
            mp2[s[r]]++;
            if(mp1.find(s[r])!=mp1.end()&&mp1[s[r]]==mp2[s[r]])
            {
                formed++;
            }
            while(l<=r&&formed==required)
            {
                if(res>r-l+1)
                {
                    res = r-l+1;
                    x=l;
                    y=r;
                }
                mp2[s[l]]--;
                if(mp1.find(s[l])!=mp1.end()&&mp2[s[l]]<mp1[s[l]])
                {
                    formed--;
                }
                l++;
            }
            r++;
        }
        if(res==INT_MAX)return "";
        else return s.substr(x,y-x+1);
    }
};