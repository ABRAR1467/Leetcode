class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int cnt = 0;
        vector<int>freq(101,0);
        for(auto height : heights)
        {
            freq[height]++;
        }
        int curheight = 0;
        for(int i=0;i<heights.size();i++)
        {
            while(freq[curheight]==0)
            {
                curheight++;
            }
            if(curheight!=heights[i])
            {
                cnt++;
            }
            freq[curheight]--;
        }
        return cnt;
    }
};