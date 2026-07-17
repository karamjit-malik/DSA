class Solution {
public:
    unordered_map<int,int> m;
    int n;
    map<pair<int,int>, bool> dp;
    bool canCross(vector<int>& stones)
    {
        n = stones.size();
        for(int i = 0; i < n; i++)
        m[stones[i]] = i;
        return sub(stones, 0, 0);
    }
    bool sub(vector<int>& stones, int jmp, int idx)
    {
        if(idx == n - 1)
        return true;
        if(dp.find({idx, jmp}) != dp.end())
        return dp[{idx, jmp}];
        bool res = false;
        for(int i = jmp - 1; i <= jmp + 1; i++)
        {
            if(i > 0)
            {
                int nxt = stones[idx] + i;
                if(m.find(nxt) != m.end())
                {
                    res = res || sub(stones, i, m[nxt]);
                    if(res)
                    break;
                }
            }
        }
        return dp[{idx, jmp}] = res;
    }
};