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
                if(checkPossible(words[i],words[j]) && dp[i] < dp[j]+1)
                dp[i] = dp[j]+1;
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
    bool checkPossible(string &s, string &t)
    {
        if(s.size() != t.size() + 1)
        return false;
        int i = 0, j = 0;
        while(i < s.size())
        {
            if(j < t.size() && s[i] == t[j])
            {
                i++, j++;
            }
            else
            i++;
        }
        if(i == s.size() && j == t.size())
        return true;
        return false;
    }
};