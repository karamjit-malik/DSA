class Solution {
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        if(k>=n)
        return "0";
        if(n == 0)
        return "0";        
        stack<char> s;
        for(int i = 0 ; i<n ; i++)
        {
            while(!s.empty() && k>0 && s.top()-'0' > num[i]-'0')
            {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(k>0)
        {
            s.pop();
            k--;
        }
        string res = "";
        while(!s.empty())
        {
            res += s.top();
            s.pop();
        }
        reverse(res.begin(), res.end());
        int i = 0;
        while(i < res.size() && res[i] == '0')
        i++;
        res = res.substr(i);
        if(res.empty())
        return "0";
        return res;
    }
};