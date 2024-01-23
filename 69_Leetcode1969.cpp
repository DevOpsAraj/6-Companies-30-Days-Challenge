#define mod 1000000007
class Solution
{
private:
    long long power(long long x, long long y)
    {
        if (y == 0)
        {
            return 1;
        }
        long long ans = power(x, y / 2);
        if (y % 2 == 0)
        {
            return (ans * ans) % mod;
        }
        else
        {
            return (((ans * ans) % mod) * (x % mod)) % mod;
        }
    }

public:
    int minNonZeroProduct(int p)
    {
        long long maxi = pow(2, p);
        long long max = maxi - 1;
        long long result = power((max - 1), ((max - 1) / 2));
        return (result * (max % mod)) % mod;
    }
};