class Solution {
public:
    bool isPalindromic(string s)
    {
        int n = s.size();

        int lChar = 0;
        int lBit = 7;

        int rChar = n - 1;
        int rBit = 0;

        while(lChar < n && rChar >= 0)
        {
            int bit1 = (s[lChar] >> lBit) & 1;
            int bit2 = (s[rChar] >> rBit) & 1;

            if(bit1 != bit2)
                return false;
            lBit--;
            if(lBit < 0)
            {
                lBit = 7;
                lChar++;
            }
            rBit++;
            if(rBit > 7)
            {
                rBit = 0;
                rChar--;
            }
        }
        return true;
    }
};