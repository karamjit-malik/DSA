class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat)
    {
        int r = mat.size();
        int c = mat[0].size();
        vector<int> ans;
        for (int k = 0; k < r + c - 1; k++)
        {
            vector<int> diagonal;
            for (int i = 0; i < r; i++)
            {
                int j = k - i;

                if (j >= 0 && j < c)
                {
                    diagonal.push_back(mat[i][j]);
                }
            }
            if (k % 2 == 0)
            {
                reverse(diagonal.begin(), diagonal.end());
            }
            for (int x : diagonal)
            {
                ans.push_back(x);
            }
        }
        return ans;
    }
};