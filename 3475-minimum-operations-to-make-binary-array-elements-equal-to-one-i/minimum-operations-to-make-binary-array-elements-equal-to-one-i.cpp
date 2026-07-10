class Solution {
public:
    int minOperations(vector<int>& nums)
    {
        int n = nums.size();
        int count = 0;
        for(int i = 0 ; i<=n-3 ; i++)
        {
            if(nums[i] == 0)
            {
                nums[i] = 1;
                if(nums[i+1] == 0)
                nums[i+1] = 1;
                else
                nums[i+1] = 0;
                if(nums[i+2] == 0)
                nums[i+2] = 1;
                else
                nums[i+2] = 0;
                count++;
            }
        }
        return accumulate(nums.begin(),nums.end(),0) == n ? count : -1;
    }
};