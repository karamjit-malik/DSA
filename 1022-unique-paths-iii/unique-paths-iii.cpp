class Solution {
public:
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
    int uniquePathsIII(vector<vector<int>>& grid)
    {
        n = grid.size();
        m = grid[0].size();
        int path = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(grid[i][j]!=-1)
                path++;
            }
        }
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(grid[i][j] == 1)
                return sub(i,j,grid,path);
            }
        }
        return -1;
    }
    int sub(int i , int j , vector<vector<int>>& grid , int path)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        return 0;
        if (grid[i][j] == -1)
        return 0;
        if (grid[i][j] == 2)
        return path == 1;
        int temp = grid[i][j];
        grid[i][j] = -1; 
        int ways = 0;
        for (auto [di, dj] : dir)
        ways += sub(i + di, j + dj, grid, path - 1);
        grid[i][j] = temp;    
        return ways;
    }
};