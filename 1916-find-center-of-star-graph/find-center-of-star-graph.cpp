class Solution {
public:
    int findCenter(vector<vector<int>>& edges)
    {
        int maxNode = 0;
        for (auto &e : edges)
        maxNode = max(maxNode, max(e[0], e[1]));
        vector<vector<int>> adj(maxNode + 1);
        vector<int> degree(maxNode + 1, 0);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        int remaining = maxNode;
        for (int i = 1; i <= maxNode; i++)
        {
            if (degree[i] == 1)
            q.push(i);
        }
        while (remaining > 1)
        {
            int sz = q.size();
            remaining -= sz;
            while (sz--)
            {
                int node = q.front();
                q.pop();
                for (int nei : adj[node])
                {
                    degree[nei]--;
                    if (degree[nei] == 1)
                    q.push(nei);
                }
            }
        }
        return q.front();
    }
};