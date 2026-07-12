class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int n = nums.size();
        int i,j;
        for(i = n-2 ; i>=0 ; i--)
        {
            if(nums[i+1] > nums[i])
            break;
        }
        if(i == -1)
        {
            reverse(nums.begin(),nums.end());
            return ;
        }
        
        j = n-1;
        while(j>i)
        {
            if(nums[j] > nums[i])
            {
                swap(nums[i],nums[j]);
                break;
            }
            j--;
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};