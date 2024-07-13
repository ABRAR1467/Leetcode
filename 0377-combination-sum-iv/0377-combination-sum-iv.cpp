class Solution {
    int func(vector<int>&nums,int target,vector<int>&dp)
    {
        if(target==0)
        {
            return 1;
        }
        if(dp[target]!=-1)return dp[target];
        int res = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=target)
            {
                res+=func(nums,target-nums[i],dp);
            }
            dp[target]=res;
        }
        return dp[target];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        dp[0]=1;
        func(nums,target,dp);
        return dp[target]==-1?0:dp[target];
    }
};