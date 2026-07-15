class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank)
    {
        unordered_set<string> s(bank.begin(), bank.end());
        if(s.find(endGene) == s.end())
        return -1;
        queue<string> q;
        q.push(startGene);
        s.erase(startGene);
        int count = 0;
        string genes = "ACGT";
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                string top = q.front();
                q.pop();
                if(top == endGene)
                return count;
                for(int i = 0; i < top.size(); i++)
                {
                    char original = top[i];
                    for(char ch : genes)
                    {
                        if(ch == original)
                        continue;
                        top[i] = ch;
                        if(s.find(top) != s.end())
                        {
                            q.push(top);
                            s.erase(top);
                        }
                    }
                    top[i] = original;
                }
            }
            count++;
        }
        return -1;
    }
};