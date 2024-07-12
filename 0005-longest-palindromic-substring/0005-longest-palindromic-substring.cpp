class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>>dp(1001,vector<int>(1001,-1));
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        int len = 1;
        int start = 0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                start = i;
                len=2;
            }
        }
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j = i+k-1;
                if(s[i]==s[j]&&dp[i+1][j-1]==1)
                {
                    dp[i][j]=1;
                    if(len<k)
                    {
                        len = k;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,len);
    }
};