class Solution{
public:
    bool sumGame(string& num)
    {
        int n = num.size();
        int L = 0, R = 0;
        int qL = 0, qR = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (num[i] == '?')
            qL++;
            else
            L += num[i] - '0';
            if (num[n / 2 + i] == '?')
            qR++;
            else
            R += num[n / 2 + i] - '0';
        }
        return 2 * (L - R) + 9 * (qL - qR) != 0;
    }
};