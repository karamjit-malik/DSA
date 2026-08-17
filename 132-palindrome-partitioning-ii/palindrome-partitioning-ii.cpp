class Solution {
public:
int n;
vector<int> dp;
    // int minCut(string s)
    // {
    //     n = s.size();
    //     if(n<=1)
    //     return 0;
    //     dp.resize(n,-1);
    //     return solve(0,s);
    // }
    // int solve(int i , const string& s)
    // {
    //     if(i == n)
    //     return 0;
    //     if(dp[i]!=-1)
    //     return dp[i];
    //     int mincost = INT_MAX;
    //     string temp = "";
    //     for(int j = i ; j<n ; j++)
    //     {
    //         temp+=s[j];
    //         int cost;
    //         if(ispalindrome(temp))
    //         {
    //             if(j == n-1)
    //             cost = 0;
    //             else
    //             cost = 1+solve(j+1,s);
    //         }
    //         mincost = min(mincost,cost);
    //     }
    //     return dp[i] = mincost;
    // }
    bool ispalindrome(const string& s)
    {
        int m = s.size();
        for(int i = 0 ; i<m/2 ; i++)
        {
            if(s[i]!=s[m-1-i])
            return false;
        } 
        return true;
    }
    int minCut(string s)
    {
        n = s.size();
        if(n<=1)
        return 0;
        dp.resize(n,0);
        for(int i = n-1 ; i>=0 ; i--)
        {
            int mincost = INT_MAX;
            string temp = "";
            for(int j = i ; j<n ; j++)
            {
                temp+=s[j];
                int cost;
                if(ispalindrome(temp))
                {
                    if(j == n-1)
                    cost = 0;
                    else
                    cost = 1+dp[j+1];
                }
                mincost = min(mincost,cost);
            }
            dp[i] = mincost;
        }
        return dp[0];
    }
};