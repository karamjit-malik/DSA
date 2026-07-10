class Solution {
public:
    int longestStrChain(vector<string>& words)
    {
        int n = words.size();
        sort(words.begin(),words.end(),[](string a , string b)
        {
            if(a.size() != b.size())
            return a.size() < b.size();
            return a<b;
        });
        vector<int> dp(n,1);
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<i ; j++)
            {
                if(words[i].size() == words[j].size()+1 && lcs(words[i],words[j]) && dp[i] < dp[j]+1)
                dp[i] = dp[j]+1;
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
    bool lcs(string s1 , string s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = 0 ; i<n ; i++)
        dp[i][0] = 0;
        for(int i = 0 ; i<m ; i++)
        dp[0][i] = 0;

        for(int i = 1 ; i<=n ; i++)
        {
            for(int j = 1 ; j<=m ; j++)
            {
                if(s1[i-1] == s2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
                else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m] == m;
    }
};