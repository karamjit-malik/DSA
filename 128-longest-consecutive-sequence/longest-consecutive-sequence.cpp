class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int n = nums.size();
        if(n<=1)
        return n;
        int ans = 1;
        unordered_set<int> s(nums.begin(),nums.end());
        int longest = 0;
        for(int i : s)
        {
            if(s.find(i-1) == s.end())
            {
                int num = i;
                int count = 1;
                while(s.find(num+1)!=s.end())
                {
                    num++;
                    count++;
                }
                longest = max(longest,count);
            }
        }
        return longest;
    }
};