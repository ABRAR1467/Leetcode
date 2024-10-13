class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        for(int i=0;i<k;i++)
        {
            pq.push({nums[i][0],i,0});
            max_val = max(max_val,nums[i][0]);
            min_val = min(min_val,nums[i][0]);
        }
        int min_l = min_val;
        int max_r = max_val;
        while(1)
        {
            auto it = pq.top();
            pq.pop();

            int r = it[1];
            int c = it[2];
            int curr = it[0];

            if(max_r-min_l>max_val-curr)
            {
                min_l = curr;
                max_r = max_val;
            }

            if(c<nums[r].size()-1)
            {
                pq.push({nums[r][c+1],r,c+1});
                max_val = max(max_val,nums[r][c+1]);
            }
            else
            {
                break;
            }
        }
        return {min_l,max_r};
    }
};