class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m);
        int ans = 0;
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(matrix[i][j] == '1')
                height[j]++;
                else
                height[j] = 0;
            }
            ans = max(ans, largestRectangleArea(height));
        }
        return ans;
    }
    vector<int> large(vector<int>& heights)
    {
        int n = heights.size();
        vector<int> nse(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
            if (st.empty())
            nse[i] = n;
            else
            nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> small(vector<int>& heights)
    {
        int n = heights.size();
        vector<int> pse(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
            if (st.empty())
            pse[i] = -1;
            else
            pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        vector<int> pse = small(heights);
        vector<int> nse = large(heights);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            ans = max(ans, area);
        }
        return ans;
    }
};