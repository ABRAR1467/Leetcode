class Solution {
public:
    bool possible(vector<int>&bloomDay,int m,int k,int x)
    {
        int n = bloomDay.size();
        int cnt = 0;
        int nofB = 0;
        for(int i=0;i<n;i++)
        {
            if(bloomDay[i]<=x)
            {
                
                cnt++;
            }
            else
            {
                nofB += (cnt/k);
                cnt = 0;
            }
        }
        nofB+=(cnt/k);
        return nofB>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long v = 1LL*m*1LL*k;
        if(v>n) return -1;
        int mn = 1e9,mx = INT_MIN;
        for(int i=0;i<n;i++)
        {
            mn = min(mn,bloomDay[i]);
            mx = max(mx,bloomDay[i]);
        }
        int low = mn,high = mx;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(possible(bloomDay,m,k,mid))
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return low;
        
    }
};