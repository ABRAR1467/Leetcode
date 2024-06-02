class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        set<int>prev;
        for(int i=0;i<n;i++)
        {
            set<int>curr;
            for(auto &v : prev)
            {
                curr.insert(v&nums[i]);
            }
            curr.insert(nums[i]);
            for(auto &v:curr)
            {
                ans = min(ans,abs(k-v));
            }
            prev = curr;
        }
        return ans;
    }
};