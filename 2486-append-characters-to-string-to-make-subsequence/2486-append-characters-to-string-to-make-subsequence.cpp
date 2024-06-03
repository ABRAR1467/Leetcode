class Solution {
public:
    int appendCharacters(string s, string t) {
        int ans;
        int j = 0;
        for(int i=0;i<s.size()&&j<t.size();i++)
        {
            if(s[i]==t[j])
            {
                j++;
            }
        }
        ans = t.size()-j;
        return ans;
    }
};