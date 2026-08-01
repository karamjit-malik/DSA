class Solution {
public:
    int maxCoins(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 0)
        return 0;
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        n+=2;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(nums,dp,1,n-2);
    }
    int solve(vector<int>& nums , vector<vector<int>>& dp , int i , int j)
    {
        if(i>j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int maxi = 0;
        for(int k = i ; k<=j ; k++)
        {
            int steps = nums[i-1]*nums[k]*nums[j+1] + solve(nums,dp,i,k-1) + solve(nums,dp,k+1,j);
            maxi = max(maxi,steps);
        }
        return dp[i][j] = maxi;
    }
};