class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return sub(nums, dp, 0, -1);
    }
    int sub(vector<int>& nums, vector<vector<int>>& dp, int i, int prev)
    {
        if(i == nums.size())
        return 0;
        if(dp[i][prev + 1] != -1)
        return dp[i][prev + 1];
        int take = 0;
        if(prev == -1 || nums[i] > nums[prev])
        take = 1 + sub(nums, dp, i + 1, i);
        int notake = sub(nums, dp, i + 1, prev);
        return dp[i][prev + 1] = max(take, notake);
    }
};