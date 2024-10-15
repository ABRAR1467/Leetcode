class Solution {
public:
    long long minimumSteps(string s) {
        long long l=0,r=s.size()-1;
        long long ans = 0;
        while(l<r)
        {
            while(l<r&&s[l]=='0')l++;
            while(l<r&&s[r]=='1')r--;
            if(s[l]=='1'&&s[r]=='0')
            {
                ans+=(r-l);
                l++;
                r--;
            }
        }
        return ans;
    }
};