class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        unordered_map<int, int> freqs;
        int i = 0, j = 0, len = nums.size(), overKs = 0, lmt = k + 1;
        while (j < len)
        {
            if (++freqs[nums[j++]] == lmt)
                overKs++;
            if (overKs && --freqs[nums[i++]] == k)
                overKs--;
        }
        return len - i;
    }
};