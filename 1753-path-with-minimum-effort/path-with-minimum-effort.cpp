class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& nums)
    {
        int n = nums.size();
        int m = nums[0].size();
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> heap;
        dist[0][0] = 0;
        heap.push({0,{0,0}});
        while(!heap.empty())
        {
            int dis = heap.top().first;
            int i = heap.top().second.first;
            int j = heap.top().second.second;
            heap.pop();
            if(dis > dist[i][j])
            continue;
            if(i == n-1 && j == m-1)
            return dis;
            for(auto &[dx,dy] : dir)
            {
                int x = i + dx;
                int y = j + dy;
                if(x>=0 && y>=0 && x<n && y<m)
                {
                    int effort = max(dis,abs(nums[x][y] - nums[i][j]));
                    if(effort < dist[x][y])
                    {
                        dist[x][y] = effort;
                        heap.push({effort,{x,y}});
                    }
                }
            }
        }
        return 0;
    }
};