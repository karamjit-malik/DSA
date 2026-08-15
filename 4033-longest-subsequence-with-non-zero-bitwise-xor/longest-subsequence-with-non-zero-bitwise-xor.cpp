class Solution {
public:
    int longestSubsequence(vector<int>& nums)
    {
        int ans = 0;
        for (int b = 0; b < 30; b++)
        {
            const int NEG = INT_MIN;
            int next[2] = {NEG, 0};
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                int nb = (nums[i] >> b) & 1;
                int cur[2];
                for (int p = 0; p < 2; p++)
                {
                    cur[p] = max(1 + next[p ^ nb],next[p]);
                }
                next[0] = cur[0];
                next[1] = cur[1];
            }
            ans = max(ans, next[0]);
        }
        return ans;
    }
};