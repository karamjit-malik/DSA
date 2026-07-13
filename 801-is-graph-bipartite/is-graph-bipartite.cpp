class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<int> vis(n,0);
        queue<int> q;
        for(int i = 0 ; i<n ; i++)
        {
            if(vis[i] == 0)
            {
                q.push(i);
                vis[i] = 1;
                while(!q.empty())
                {
                    int top = q.front();
                    q.pop();
                    for(int i : graph[top])
                    {
                        if(vis[i] == 0)
                        {
                            vis[i] = -vis[top];
                            q.push(i);
                        }
                        else if(vis[i] == vis[top])
                        return false;
                    }
                } 
            }
        }
        return true;      
    }
};