class Solution {
public:
    vector<int> resultArray(vector<int>& nums)
    {
        vector<int> arr1, arr2;
        int i=0;
        arr1.push_back(nums[i++]);
        arr2.push_back(nums[i++]);
        while(i < nums.size())
        {
            if(arr1.back() > arr2.back()) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
            i++;
        }
        i=0;
        while(i < arr1.size())
        {
            nums[i] = arr1[i];
            i++;
        }
        int j = 0;
        while(j < arr2.size())
        {
            nums[i+j] = arr2[j];
            j++;
        }
        return nums;
    }
};