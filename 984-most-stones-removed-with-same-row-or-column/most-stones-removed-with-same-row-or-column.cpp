class DSU
{
    vector<int> parent;
    vector<int> size;
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
    int removeStones(vector<vector<int>>& stones)
    {
        int n = stones.size();
        if(n <= 1)
        return 0;
        DSU dsu(n);
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        for(int i = 0; i < n; i++)
        {
            int r = stones[i][0];
            int c = stones[i][1];
            if(row.find(r) != row.end())
            dsu.unite(i, row[r]);
            else
            row[r] = i;
            if(col.find(c) != col.end())
            dsu.unite(i, col[c]);
            else
            col[c] = i;
        }
        int connected = 0;
        for(int i = 0 ; i<n ; i++)
        {
            if(dsu.find(i) == i)
            connected++;
        }
        return n-connected;
    }
};