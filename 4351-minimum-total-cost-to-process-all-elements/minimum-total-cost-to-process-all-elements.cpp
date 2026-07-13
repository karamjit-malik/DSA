class Solution {
public:
    static const int MOD = 1e9 + 7;

    int minimumCost(vector<int>& nums, int k)
    {
        long long r = k;
        long long opr = 0;
        long long cost = 0;

        for (int x : nums)
        {
            if (r < x)
            {
                long long need = x - r;
                long long addOps = (need + k - 1) / k;
                __int128 first = opr + 1;
                __int128 last = opr + addOps;
                __int128 cnt = addOps;
                __int128 sum = cnt * (first + last) / 2;
                cost = (cost + (long long)(sum % MOD)) % MOD;
                opr += addOps;
                r += addOps * 1LL * k;
            }
            r -= x;
        }
        return cost;
    }
};