class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<=4) return 0;
        sort(nums.begin(),nums.end());
        int ans = 2*1e9;
        for(int i=0,j=n-4;i<n&&j<n;i++,j++)
        {
            ans = min(ans,nums[j]-nums[i]);
        }
        return ans;
        
    }
};