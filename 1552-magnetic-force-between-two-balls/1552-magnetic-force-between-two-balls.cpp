class Solution {
    bool func(vector<int>&position,int m,int x)
    {
        int cnt=1,last = position[0];
        for(int i=1;i<position.size();i++)
        {
            if(position[i]-last>=x)
            {
                last = position[i];
                cnt++;
            }
        }
        return cnt>=m;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int low = 1;
        int high = position[n-1]-position[0];
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(func(position,m,mid))
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return high;
    }
};