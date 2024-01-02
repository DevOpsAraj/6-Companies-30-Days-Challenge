#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        sort(arr.begin(), arr.end());
        vector<int> ans;
        if (arr[0] != 1)
        {
            for (int i = 0; i < arr.size(); i++)
            {
                if (arr[i] == arr[i + 1])
                    ans.push_back(arr[i]);
            }
            ans.push_back(1);
            return ans;
        }
        int mis = 0, missingFlag = 0;
        int rep = 0, repeatingFlag = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == arr[i + 1] && repeatingFlag == 0)
            {
                rep = arr[i];
                repeatingFlag = 1;
            }
            else if ((arr[i] + 1) != arr[i + 1] && missingFlag == 0)
            {
                mis = arr[i] + 1;
                missingFlag = 1;
            }

            if (repeatingFlag == 1 && missingFlag == 1)
                break;
        }
        ans.push_back(rep);
        ans.push_back(mis);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
        return 0;
    }
}