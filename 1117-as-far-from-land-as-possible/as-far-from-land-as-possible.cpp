class Solution {
public:
    int maxDistance(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> heap;
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(grid[i][j] == 1)
                {
                    dist[i][j] = 0;
                    heap.push({0,{i,j}});
                }
            }
        }
        while(!heap.empty())
        {
            auto [wt, pos] = heap.top();
            auto [i, j] = pos;
            heap.pop();
            if(wt > dist[i][j])
            continue;
            for(auto [dx,dy] : dir)
            {
                int x = i+dx;
                int y = j+dy;
                if(x>=0 && y>=0 && x<n && y<n && grid[x][y] == 0 && dist[x][y] > 1+wt)
                {
                    dist[x][y] = 1+wt;
                    heap.push({1+wt,{x,y}});
                }
            }
        }
        int ans = -1;
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            if(grid[i][j] == 0)
            ans = max(ans,dist[i][j]);
        }
        if(ans == -1)
        return -1;
        else if(ans == INT_MAX)
        return -1;
        else
        return ans;
    }
};