class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& nums)
    {
        int n = nums.size();
        int i = 1;
        priority_queue<int,vector<int>,greater<int>> heap;
        unordered_map<int,int> m;
        for(int i = 0 ; i<n ; i++)
        {
            heap.push(nums[i]);
        }
        while(!heap.empty())
        {
            if(m.find(heap.top()) == m.end())
            {
                m[heap.top()] = i++;
            }
            heap.pop();
        }
        vector<int> ans;
        for(int i = 0 ; i<n ; i++)
        {
            ans.push_back(m[nums[i]]);
        }
        return ans;
    }
};