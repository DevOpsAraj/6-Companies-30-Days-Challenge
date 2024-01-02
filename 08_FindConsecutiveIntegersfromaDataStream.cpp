#include <bits/stdc++.h>
using namespace std;

static const int __ = []()
{ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class DataStream
{
    int i;
    int k;
    int value;

public:
    DataStream(int value, int k)
    {
        this->value = value;
        this->k = k;
        this->i = 0;
    }

    bool consec(int num)
    {
        if (num == value)
            i++;
        else
            i = 0;
        return i >= k;
    }
};

int main()
{
    // ------

    return 0;
}