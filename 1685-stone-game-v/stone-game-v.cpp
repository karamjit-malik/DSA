class Solution {
public:
vector<int> prefixsum;
vector<vector<int>> dp;
    int stoneGameV(vector<int>& stoneValue)
    {
        int n = stoneValue.size();
        if(n == 0)
        return 0;
        prefixsum.resize(n+1,0);
        for(int i = 1 ; i<=n ; i++)
        prefixsum[i] = prefixsum[i-1] + stoneValue[i-1];
        dp.resize(n,vector<int>(n,INT_MIN));
        return sub(0,n-1);
    }
    int sub(int left , int right)
    {
        if(left == right)
        return 0;
        if(dp[left][right]!=INT_MIN)
        return dp[left][right];

        int ans = INT_MIN;
        for(int i = left ; i<right ; i++)
        {
            int ls = prefixsum[i+1] - prefixsum[left];
            int rs = prefixsum[right+1] - prefixsum[i+1];
            int curr = 0;
            if(ls < rs)
            curr = ls + sub(left,i);
            else if(ls > rs)
            curr = rs + sub(i+1,right);
            else
            curr = ls + max(sub(left,i),sub(i+1,right));
            ans = max(ans,curr);
        }
        return dp[left][right] = ans;
    }
};