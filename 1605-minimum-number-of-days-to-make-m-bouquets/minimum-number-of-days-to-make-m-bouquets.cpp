class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        if((long long)m*k > n)
        return -1;
        int ans = -1;
        int i = *min_element(bloomDay.begin(),bloomDay.end());
        int j = *max_element(bloomDay.begin(),bloomDay.end());
        while(i<=j)
        {
            int mid = i+(j-i)/2;
            int bouquet = m;
            int con = k;
            for(int x = 0 ; x<n ; x++)
            {
                if(bloomDay[x]<=mid)
                {
                    con--;
                }
                else
                con = k;
                if(con == 0)
                {
                    bouquet--;
                    con = k;
                    if(bouquet == 0)
                    break;
                }
            }
            if(bouquet == 0)
            {
                ans = mid;
                j = mid-1;
            }
            else
            i = mid+1;
        }
        return ans;
    }
};