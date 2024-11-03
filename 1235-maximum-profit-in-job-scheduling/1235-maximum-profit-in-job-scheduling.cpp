class Solution {
    int n;
    int dp[50001];
    int getnext(vector<vector<int>>&arr,int l,int currentend)
    {
        int r=n-1;
        int ans = n+1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(arr[mid][0]>=currentend)
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
    int solve(int ind,vector<vector<int>>&arr)
    {
        if(ind>=n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int next = getnext(arr,ind+1,arr[ind][1]);
        int taken = arr[ind][2]+solve(next,arr);
        int nottaken = solve(ind+1,arr);
        return dp[ind] = max(taken,nottaken);
        
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        vector<vector<int>>arr(n,vector<int>(3,0));
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }
        sort(arr.begin(),arr.end());
        return solve(0,arr);
    }
};