class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int x=numBottles;
        int ans = x;
        while(x>=numExchange)
        {
            int rem = x%numExchange;
            int mul = x/numExchange;
            x=mul+rem;
            ans+=mul;
        }
        return ans;
    }
};