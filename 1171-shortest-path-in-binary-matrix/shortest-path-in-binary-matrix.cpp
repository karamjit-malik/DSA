class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
        return -1;
        auto comp = [](pair<pair<int,int>,int> a,pair<pair<int,int>,int> b)
        {
            return a.second > b.second;
        };
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        priority_queue<pair<pair<int,int>,int> , vector<pair<pair<int,int>,int>> , decltype(comp)> heap(comp);
        dist[0][0] = 1;
        heap.push({{0,0},1});
        while(!heap.empty())
        {
            int i = heap.top().first.first;
            int j = heap.top().first.second;
            int dis = heap.top().second;
            heap.pop();
            if(dis > dist[i][j])
            continue;
            if(i == n-1 && j == m-1)
            return dis;
            for(auto [dx,dy] : dir)
            {
                int x = i + dx;
                int y = j + dy;
                if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 0)
                {
                    if(dis + 1 < dist[x][y])
                    {
                        dist[x][y] = dis + 1;
                        heap.push({{x,y}, dis + 1});
                    }
                }
            }
        }
        return -1;
    }
};