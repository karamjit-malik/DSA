class Solution {
public:
    int missingMultiple(vector<int>& nums, int k)
    {
        unordered_set<int> st(nums.begin(), nums.end());
        int mul =k;
        while(st.count(mul)) {
            mul +=k;
        }
        return mul;
    }
};