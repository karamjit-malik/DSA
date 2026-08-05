class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations)
    {
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(auto i : invocations)
        {
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        vector<int> ans;
        dfs(k,adj,vis);
        for(auto i : invocations)
        {
            int u = i[0];
            int v = i[1];
            if(vis[u] == 0 && vis[v] == 1)
            {
                for(int i = 0 ; i<n ; i++)
                ans.push_back(i);
                return ans;
            }
        }
        for(int i = 0 ; i<n ; i++)
        {
            if(vis[i] == 0)
            ans.push_back(i);
        }
        return ans;
    }
    void dfs(int k , vector<vector<int>>& adj , vector<int>& vis)
    {
        if(vis[k] == 1)
        return ;
        vis[k] = 1;
        for(int i : adj[k])
        {
            dfs(i,adj,vis);
        }
        return ;
    }
};