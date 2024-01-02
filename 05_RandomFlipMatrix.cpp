#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    unordered_set<int> st;
    int rows;
    int cols;
    int total;

public:
    Solution(int m, int n)
    {
        rows = m;
        cols = n;
        total = m * n;
    }
    vector<int> flip()
    {
        if (st.size() == total)
            return {};
        int index = rand() % total;
        while (st.count(index))
            index = ++index % total;
        st.insert(index);
        return {index / cols, index % cols};
    }
    void reset()
    {
        st.clear();
    }
};

int main()
{
    // ------
    return 0;
}