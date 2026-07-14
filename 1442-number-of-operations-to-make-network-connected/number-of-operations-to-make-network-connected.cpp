class DSU
{
    vector<int> parent,size;
    public:
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n,1);
        for(int i = 0 ; i<n ; i++)
        parent[i] = i;
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
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        DSU dsu(n);
        int size = connections.size();
        if(size < n-1)
        return -1;
        vector<vector<int>> adj(size);
        for(auto i : connections)
        {
            dsu.unite(i[0],i[1]);
        }
        int connected = 0;
        for(int i = 0 ; i<n ; i++)
        {
            if(dsu.find(i) == i)
            connected++;
        }
        return connected-1;
    }
};