class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(auto it : s)
        {
            mp[it]++;
        }
        int mx = 0,ans = 0;
        for(auto it : mp)
        {
            if(it.second%2)
            {
                mx = max(mx,it.second);
                ans+=it.second-1;
            }
            else
            {
                ans+=it.second;
            }
        }
        if(mx)ans++;
        return ans;
    }
};