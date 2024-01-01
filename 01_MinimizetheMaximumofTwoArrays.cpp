#include <bits/stdc++.h>
using namespace std;

#define ll long long int
class Solution
{
public:
    ll gcd(ll a, ll b)
    {
        return __gcd(a, b);
    }

    ll lcm(ll a, ll b)
    {
        return (a * b) / gcd(a, b);
    }

    ll getUniqueNumbersNotDivisibleBy(ll d, ll n)
    {
        return n - (n / d);
    }

    bool isGood(int d1, int d2, int n, int cnt1, int cnt2)
    {
        int one = getUniqueNumbersNotDivisibleBy(d1, n);
        int two = getUniqueNumbersNotDivisibleBy(d2, n);
        int both = getUniqueNumbersNotDivisibleBy(lcm(d1, d2), n);

        int NotDivOnlyByOne = both - two;
        int NotDivOnlyByTwo = both - one;

        cnt1 = max(0, cnt1 - NotDivOnlyByOne);
        cnt2 = max(0, cnt2 - NotDivOnlyByTwo);

        return cnt1 + cnt2 <= both - NotDivOnlyByOne - NotDivOnlyByTwo;
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2)
    {

        ll ans = 1e18;
        ll start = 1, end = 1e18;

        while (start <= end)
        {
            ll mid = (start + end) / 2;
            if (isGood(divisor1, divisor2, mid, uniqueCnt1, uniqueCnt2))
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }

        return ans;
    }
};

int main()
{
    int divisor1, divisor2, uniqueCnt1, uniqueCnt2;
    cin >> divisor1 >> divisor2 >> uniqueCnt1 >> uniqueCnt2;
    Solution obj;
    cout << obj.minimizeSet(divisor1, divisor2, uniqueCnt1, uniqueCnt2);
    return 0;
}