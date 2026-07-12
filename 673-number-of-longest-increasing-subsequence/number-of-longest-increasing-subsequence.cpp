class Solution {
public:
    int findNumberOfLIS(vector<int>& nums)
    {
        int n = nums.size(),maxi = 0;
        vector<int> dp(n,1),cnt(n,1);
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<i ; j++)
            {
                if(nums[i] > nums[j] && dp[i] < dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                    cnt[i] = cnt[j];
                }
                else if(nums[i] > nums[j] && dp[i] == dp[j]+1)
                cnt[i]+=cnt[j];
            }
            maxi = max(maxi,dp[i]);
        }
        int nos = 0;
        for(int i = 0 ; i<n ; i++)
        {
            if(dp[i] == maxi)
            nos+=cnt[i];
        }
        return nos;
    }
};