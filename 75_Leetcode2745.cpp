class Solution
{
public:
    int longestString(int x, int y, int z)
    {
        return 2 * (min(x, y) * 2 + z + (x != y));
    }
};