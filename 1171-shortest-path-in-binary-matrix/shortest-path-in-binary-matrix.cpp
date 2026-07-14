class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
        return -1;
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            int curr = grid[i][j];
            if(i == n-1 && j == n-1)
            return curr;
            for(auto [dx,dy] : dir)
            {
                int x = i+dx , y = j+dy;
                if(x>=0 && x<n && y>=0 && y<n && grid[x][y] == 0)
                {
                    grid[x][y] = curr+1;
                    q.push({x,y});
                }
            }
        }
        return -1;
    }
};