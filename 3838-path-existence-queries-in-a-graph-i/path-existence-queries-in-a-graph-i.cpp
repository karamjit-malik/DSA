class DSU
{
    vector<int> parent , size;
    public:
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n,1);

        for(int i = 0 ; i<n ; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if(parent[x] == x)
        return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a , int b)
    {
        a = find(a);
        b = find(b);
        if(a!=b)
        {
            if(size[a] < size[b])
            swap(a,b);
            parent[b] = a;
            size[a]+=size[b];
        }
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries)
    {
        DSU dsu(n);
        for(int i = 1; i < n; i++)
        {
            if(nums[i] - nums[i-1] <= maxDiff)
            dsu.unite(i, i-1);
        }
        vector<bool> ans;
        for(auto &q : queries)
        {
            int u = q[0];
            int v = q[1];
            ans.push_back(dsu.find(u) == dsu.find(v));
        }
        return ans;
    }
};