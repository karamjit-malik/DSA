class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> temp(n,-1);
        int maxi = 1 , last = 0;
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<i ; j++)
            {
                if(nums[i]%nums[j] == 0 && dp[i] < dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                    temp[i] = j;
                }
            }
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                last = i;
            }
        }
        vector<int> ans;
        int curr = last;
        while(curr!=-1)
        {
            ans.push_back(nums[curr]);   
            curr = temp[curr];
        }
        return ans;
    }
};