class Solution {
public:

    int deleteAndEarn(vector<int>& nums)
    {
        vector<int> points(10001,0);
        for(auto x: nums)
        points[x] += x;
        vector<int> dp(10001,0);
        dp[1] = points[1];
        for(int i=2;i<=10000;i++)
        dp[i] = max(dp[i-1],points[i]+dp[i-2]);    
        return dp[10000];
    }
};