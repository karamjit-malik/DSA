class Solution {
public:
    bool judgeCircle(string moves)
    {
        unordered_map<char,int> m;
        for(char c : moves)
        m[c]++;

        return m['U'] == m['D'] && m['L'] == m['R'];
        
    }
};