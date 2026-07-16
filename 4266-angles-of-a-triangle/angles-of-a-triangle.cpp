class Solution {
public:
    vector<double> internalAngles(vector<int>& s)
    {
        double a = s[0],b=s[1],c=s[2];
        const double pie = 3.14159265358979323846;
        vector<double> ans;
        if(a+b >c and b+c >a and c+a >b and a!=0 and b!=0 and c!=0)
        {
            double A = acos((b*b + c*c - a*a) / (2*b*c));
            double B = acos((a*a + c*c - b*b) / (2*a*c));
            double C = acos((a*a + b*b - c*c) / (2*a*b));
            A *= 180.0/pie;
            B *= 180.0/pie;
            C *= 180.0/pie;
            ans = {A,B,C};
            sort(ans.begin(),ans.end());
        }
        return ans;
    }
};