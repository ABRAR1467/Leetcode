class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++)pq.push(nums[i]);
        long long score = 0;
        while(k--)
        {
            long long x = pq.top();
            pq.pop();
            score+=x;
            pq.push((x+2)/3);
        }
        return score;
        
    }
};