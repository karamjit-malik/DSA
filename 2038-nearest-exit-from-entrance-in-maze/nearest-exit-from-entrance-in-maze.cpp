class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
    {
        int n = maze.size();
        int m = maze[0].size();
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        q.push({{entrance[0],entrance[1]},0});
        vis[entrance[0]][entrance[1]] = 1;
        while(!q.empty())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            if ((i == 0 || i == n-1 || j == 0 || j == m-1) && !(i == entrance[0] && j == entrance[1]))
            {
                return dist;
            }
            for(auto& [dx,dy] : dir)
            {
                int x = i+dx;
                int y = j+dy;
                if(x>=0 && y>=0 && x<n && y<m && !vis[x][y] && maze[x][y] == '.')
                {
                    vis[x][y] = 1;
                    q.push({{x,y},dist+1});
                }
            }
        }
        return -1;
    }
};