class Solution {
public:
    int longestCycle(vector<int>& edges)
    {
        int n = edges.size();
        vector<int> indegree(n,0);
        for(int i = 0; i < n; i++)
        {
            if(edges[i] != -1)
            indegree[edges[i]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            q.push(i);
        }
        vector<int> removed(n,0);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            removed[node] = 1;
            int next = edges[node];
            if(next != -1)
            {
                indegree[next]--;
                if(indegree[next] == 0)
                q.push(next);
            }
        }
        int ans = -1;
        vector<int> vis(n,0);
        for(int i = 0; i < n; i++)
        {
            if(removed[i] || vis[i])
            continue;
            int cnt = 0;
            int cur = i;
            while(!vis[cur])
            {
                vis[cur] = 1;
                cnt++;
                cur = edges[cur];
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};