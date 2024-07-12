class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int l = 0;
        int ans = 0;
        int cnt = 0;
        for(int r=0;r<s.size();r++)
        {
            mp[s[r]]++;
            for(char ch='A';ch<='Z';ch++)
            {
                cnt = max(cnt,mp[ch]);
            }
            while((r-l+1-cnt)>k)
            {
                mp[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};