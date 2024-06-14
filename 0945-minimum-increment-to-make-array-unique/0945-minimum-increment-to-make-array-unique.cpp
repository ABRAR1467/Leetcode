class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int>freq(200001,0);
        int mn=1e5;
        for(int x : nums)
        {
            freq[x]++;
            mn = min(mn,x);
        }
        int res = 0,cnt = 0;
        for(int i=mn;cnt<n;i++)
        {
            int f = freq[i];
            cnt+=(f!=0);
            if(f<=1)continue;
            freq[i+1]+=(f-1);
            res+=(f-1);
        }
        return res;
    }
};