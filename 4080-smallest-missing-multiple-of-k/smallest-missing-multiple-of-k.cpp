class Solution {
public:
    int missingMultiple(vector<int>& nums, int k)
    {
        int n = nums.size();
        if(k == 0 || n == 0)
        return 0;
        vector<int> hash(1000,0);
        for(int i : nums)
        hash[i]++;

        for(int i = k ; i<1000 ; i+=k)
        if(hash[i] == 0)
        return i;

        return -1;
    }
};