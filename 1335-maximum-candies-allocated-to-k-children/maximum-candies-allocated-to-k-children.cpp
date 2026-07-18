class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k)
    {
        int n = candies.size();
        int i = 1;
        int j = *max_element(candies.begin(), candies.end());
        while(i<=j)
        {
            int mid = i+(j-i)/2;
            long long child = 0;
            for(int x = 0 ; x<n ; x++)
            {
                child += candies[x] / mid;
            }
            if(child >= k)
            i = mid+1;
            else
            j = mid-1;
        }
        return j;
    }
};