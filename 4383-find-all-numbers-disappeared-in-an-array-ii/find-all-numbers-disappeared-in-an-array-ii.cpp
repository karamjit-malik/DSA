class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper)
    {
        int n = nums.size();
        if(n == 0)
        return {{lower,upper}};
        vector<int> hash(upper+1,1);
        for(int i = 0 ; i<n ; i++)
        {
            if(nums[i] >= lower && nums[i] <= upper)
            hash[nums[i]] = 0;
        }
        vector<vector<int>> res;
        for(int i = lower ; i<=upper ; i++)
        {
            if(hash[i] == 0)
            continue;
            int j = i;
            while(j<=upper && hash[j]!=0)
            j++;
            res.push_back({i,j-1});
            i = j-1;
        }
        return res;
    }
};