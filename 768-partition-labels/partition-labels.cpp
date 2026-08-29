class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        int n = s.size();
        unordered_map<char,int> m;
        for(int i = 0; i < n ; i++)
        m[s[i]] = max(m[s[i]],i);
        int last = 0;
        int idx = -1;
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            idx = max(idx,m[s[i]]);
            if(idx == i)
            {
                ans.push_back(i-last+1);
                last = i+1;
                idx = -1;
            }
        }
        return ans;
    }
};