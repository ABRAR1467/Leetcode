class Solution {
public:
    string reverseParentheses(string s) {
        vector<int>bracket;
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                bracket.push_back(ans.size());
            }
            else if(s[i]==')')
            {
                int j = bracket.back();
                bracket.pop_back();
                reverse(ans.begin()+j,ans.end());
            }
            else
            {
                ans+=s[i];
            }
        }
        return ans;
    }
};