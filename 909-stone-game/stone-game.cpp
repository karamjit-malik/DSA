class Solution {
public:
vector<vector<int>> dp;
    int solve(int left, int right, vector<int>& piles)
    {
        if(left > right)
        return 0;
        if(dp[left][right]!=-1)
        return dp[left][right];
        int takeLeft = piles[left] - solve(left+1,right,piles);
        int takeRight = piles[right] - solve(left,right-1,piles);
        return dp[left][right] = max(takeLeft,takeRight);
    }
    bool stoneGame(vector<int>& piles)
    {
        int n = piles.size();
        dp.resize(n,vector<int>(n,-1));
        return solve(0,n-1,piles) > 0;
    }
};