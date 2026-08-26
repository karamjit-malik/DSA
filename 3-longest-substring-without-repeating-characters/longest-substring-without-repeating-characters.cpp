class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char,int> m;
        int n = s.size();
        if(n == 0)
        return 0;
        int maxi = 1;
        int i = 0 , j = 0;
        while(j<n)
        {
            m[s[j]]+=1;
            if(m[s[j]]>1)
            {
                while(m[s[j]]>1)
                {
                    m[s[i]]--;
                    if(m[s[i]] == 0)
                    m.erase(s[i]);
                    i++;
                }
            }
            maxi = max(maxi,(int)m.size());
            j++;
        }
        return maxi;
    }
};