class Solution {
public:
    int maxDepth(string s)
    {
        int n = s.size();
        if(n == 0)
        return 0;
        int count = 0;
        int maxi = 0;
        for(int i = 0 ; i<n ; i++)
        {
            if(s[i] == '(')
            count++;
            else if(s[i] == ')')
            {
                maxi = max(maxi,count);
                count--;
            }
        }
        return maxi;
    }
};