class Solution
{

public:
    int maximumProduct(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int last = 1;
        int diff = 0;
        while (k > 0)
        {
            while (last < nums.size() && nums[last] == nums[0])
                last++;

            if (last < nums.size())
            {
                diff = (nums[last] - nums[0]);
                if (diff * last > k)
                    diff = k / last;
            }
            else
                diff = k / last;
            if (diff == 0)
                diff = 1;

            for (int i = 0; i < last && k > 0; i++)
            {
                nums[i] += diff;
                k -= diff;
            }

            if (last < nums.size())
                last++;
        }

        long long product = 1;
        for (auto num : nums)
            product = (product * num) % 1000000007;
        return product;
    }
};