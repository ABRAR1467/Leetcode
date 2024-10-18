class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int>freq(25,0);
        int mx=0,ans=0;
        for(int j=24;j>=0;j--)
        {
            for(int i=0;i<candidates.size();i++)
            {
                if(candidates[i]&(1<<j))
                {
                    freq[j]++;
                }
            }
            if(freq[j]>mx)
            {
                mx=freq[j];
                ans = freq[j];
            }
        }
        return ans;
    }
};