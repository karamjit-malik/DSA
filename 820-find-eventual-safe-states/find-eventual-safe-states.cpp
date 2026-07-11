class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<int> outdegree(n,0);
        vector<vector<int>> reverse(n);
        vector<int> res;
        for (int u = 0; u < n; ++u)
        {
            for (int v : graph[u])
            {
                reverse[v].push_back(u);
                outdegree[u]++;
            }
        }
        queue<int> q;
        for(int i = 0 ; i<n ; i++)
        {
            if(outdegree[i] == 0)
            q.push(i);
        }
        vector<bool> safe(n,false);
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            safe[top] = true;
            for(int i : reverse[top])
            {
                outdegree[i]--;
                if(outdegree[i] == 0)
                q.push(i);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (safe[i])
                res.push_back(i);
        }
        return res;
    }
};