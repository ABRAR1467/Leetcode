class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>v(3,0);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)v[0]++;
            else if(nums[i]==1)v[1]++;
            else v[2]++;
        }
        int k = 0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<v[i];j++)
            {
                nums[k]=i;
                k++;
            }
        }
        
    }
};