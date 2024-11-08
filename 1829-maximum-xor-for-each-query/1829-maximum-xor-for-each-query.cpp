class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int>ans(n,0);
        int maxxor = (1<<maximumBit)-1;
        int xorr = 0;
        for(int i=0;i<n;i++)
        {
            xorr^=nums[i];
        }
        int y=0;
        for(int i=0;i<n;i++)
        {
            ans[i] = maxxor^xorr;
            xorr^=nums[n-i-1];
        }
        return ans;
    }
};