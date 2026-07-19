class Solution {
public:
    vector<int> generate(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> sums;

        for(int mask = 0; mask < (1 << n); mask++)
        {
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                if(mask & (1 << i))
                sum += arr[i];
                else
                sum -= arr[i];
            }
            sums.push_back(sum);
        }
        return sums;
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        int mid = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());
        vector<int> lsum = generate(left);
        vector<int> rsum = generate(right);
        sort(rsum.begin(), rsum.end());
        long long ans = 0;
        for(int x : lsum)
        {
            int need = target - x;
            ans += upper_bound(rsum.begin(), rsum.end(), need) - lower_bound(rsum.begin(), rsum.end(), need);
        }
        return ans;
    }
};