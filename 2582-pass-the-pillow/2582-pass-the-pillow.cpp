class Solution {
public:
    int passThePillow(int n, int time) {
        int l=1;
        for(int i=1;i<=time;)
        {
            while(l<n&&i<=time)
            {
                i++;
                l++;
            }
            while(l>1&&i<=time)
            {
                i++;
                l--;
            }
    
        }
        return l;
    }
};