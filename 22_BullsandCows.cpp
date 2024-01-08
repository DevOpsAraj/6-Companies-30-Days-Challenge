#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int n = secret.size();
        int bulls = 0;
        int cows = 0;

        vector<int> secretCows(10, 0);
        vector<int> guessCows(10, 0);

        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
                bulls++;
            else
            {
                secretCows[secret[i] - '0']++;
                guessCows[guess[i] - '0']++;
            }
        }

        for (int i = 0; i < guessCows.size(); i++)
        {
            cows += min(guessCows[i], secretCows[i]);
        }

        string ans = to_string(bulls) + 'A' + to_string(cows) + 'B';
        return ans;
    }
};

int main()
{
    string secret = "1807";
    string guess = "7810";
    Solution s;
    cout << s.getHint(secret, guess) << endl;

    return 0;
}