class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear)
    {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        if(0 < disappear[0])
        {
            dist[0] = 0;
            pq.push({0,0});
        }
        while(!pq.empty())
        {
            auto [time, node] = pq.top();
            pq.pop();
            if(time > dist[node])
            continue;
            for(auto &[next, wt] : adj[node])
            {
                int newTime = time + wt;
                if(newTime < disappear[next] && newTime < dist[next])
                {
                    dist[next] = newTime;
                    pq.push({newTime, next});
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(dist[i] == INT_MAX)
            dist[i] = -1;
        }
        return dist;
    }
};