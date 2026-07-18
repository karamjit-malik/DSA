class Solution {
public:
int n , m;
    bool dfs(int i , int j , vector<vector<int>>& grid)
    {
        if (i < 0 || j < 0 || i >= n || j >= m)
        return false;
        if (grid[i][j] == 1)
        return true;
        grid[i][j] = 1;
        bool left = dfs(i, j-1 , grid), right = dfs(i, j+1 , grid), up = dfs(i-1, j , grid), down = dfs(i+1, j , grid);
        return left && right && up && down;
    }
    int closedIsland(vector<vector<int>>& grid)
    {
        n = grid.size(), 
        m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0 && dfs(i, j , grid))
                count++;  
            }
        }
        return count;
    }
};
