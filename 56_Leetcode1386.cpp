class Solution
{
    void isPresent(int seat, bool &first, bool &second, bool &third)
    {
        if (seat >= 2 && seat <= 5)
            first = false;
        if (seat >= 4 && seat <= 7)
            second = false;
        if (seat >= 6 && seat <= 9)
            third = false;
    }

public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
    {
        unordered_map<int, vector<int>> seatAlloc;
        for (int i = 0; i < reservedSeats.size(); i++)
            seatAlloc[reservedSeats[i][0]].push_back(reservedSeats[i][1]);

        int res = 0;
        for (auto x : seatAlloc)
        {
            bool first = true, second = true, third = true;
            int row = x.first;
            vector<int> seats = x.second;
            for (int i = 0; i < seats.size(); i++)
            {
                isPresent(seats[i], first, second, third);
            }

            if (first && third)
                res += 2;
            else if (first || second || third)
                res += 1;
        }

        int remRows = n - seatAlloc.size();
        res += remRows * 2;

        return res;
    }
};