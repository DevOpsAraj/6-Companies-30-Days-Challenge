class Solution
{
public:
    int wordCount(vector<string> &startWords, vector<string> &targetWords)
    {
        // create a set
        unordered_set<string> st;
        // traverse all startWords sort them and insert them into set so we can
        // search for them later
        for (auto startWord : startWords)
        {
            sort(startWord.begin(), startWord.end());
            st.insert(startWord);
        }
        int count = 0;
        // traverse all targetWord
        for (auto targetWord : targetWords)
        {
            for (int i = 0; i < targetWord.size(); i++)
            {
                // make all possible comibnations of targetWord by removing a
                // character
                string toSearch =
                    targetWord.substr(0, i) + targetWord.substr(i + 1);
                // sort the string
                sort(toSearch.begin(), toSearch.end());
                // search for the string in set and if found increase counter
                if (st.find(toSearch) != st.end())
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};