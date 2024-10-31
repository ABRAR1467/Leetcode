class Solution {
    long long inf = 100000000000000000LL;
    long long func(vector<int>& robot, vector<int>&factory,int m,int n,vector<vector<long long>>&dp)
    {
        if(m<0)return 0;
        if(n<0)return inf;
        if(dp[m][n]!=-1)return dp[m][n];
        long long exclude = func(robot,factory,m,n-1,dp);
        long long include = abs(robot[m]-factory[n])+func(robot,factory,m-1,n-1,dp);
        return dp[m][n]=min(include,exclude);
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int>newfactory;
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        for(int i=0;i<factory.size();i++)
        {
            int x = factory[i][0];
            int y = factory[i][1];
            for(int j=0;j<y;j++)
            {
                newfactory.push_back(x);
            }
        }
        int m = robot.size();
        int n = newfactory.size();
        vector<vector<long long>>dp(m,vector<long long>(n,-1));
        return func(robot,newfactory,m-1,n-1,dp);
    }
};