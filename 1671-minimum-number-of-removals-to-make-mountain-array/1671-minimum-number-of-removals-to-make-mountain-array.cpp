class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftdp(n+1,1);
        vector<int>rightdp(n+1,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    leftdp[i]=max(leftdp[i],1+leftdp[j]);
                }
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>i;j--)
            {
                if(nums[i]>nums[j])
                {
                    rightdp[i] = max(rightdp[i],1+rightdp[j]);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(leftdp[i]>1&&rightdp[i]>1)
            {
                ans = max(ans,leftdp[i]+rightdp[i]-1);
            }
        }
        return n-ans;

    }
};