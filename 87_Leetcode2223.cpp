#define ll long long
class Solution
{
public:
    vector<ll> z_fun(string str)
    {
        ll l = 0, r = 0;
        ll len = str.size();
        vector<ll> z(len);

        for (ll i = 1; i < len; i++)
        {
            if (i > r)
            {
                l = r = i;
                while (r < len and str[r] == str[r - l])
                    r++;
                z[i] = r - l;
                r--;
            }
            else
            {
                ll idx = i - l;
                if (i + z[idx] <= r)
                {
                    z[i] = z[idx];
                }
                else
                {
                    l = i;
                    while (r < len && str[r] == str[r - l])
                        r++;
                    z[i] = r - l;
                    r--;
                }
            }
        }
        return z;
    }
    long long sumScores(string s)
    {
        vector<ll> z = z_fun(s);
        return accumulate(z.begin(), z.end(), 0LL) + s.size();
    }
};