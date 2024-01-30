class TrieNode
{
public:
    TrieNode *next[26] = {};
    bool is_leaf = false;
    TrieNode() {}
};

class Trie
{
public:
    Trie() {}
    void insert(string word)
    {
        auto curr = root;
        for (auto &c : word)
        {
            if (!curr->next[c - 'a'])
                curr->next[c - 'a'] = new TrieNode();
            curr = curr->next[c - 'a'];
        }
        curr->is_leaf = true;
    }

    bool search(string &word, int i, TrieNode *curr)
    {
        for (; i < word.size(); i++)
        {
            if (word[i] == '.')
            {
                for (int j = 0; j < 26; j++)
                    if (curr->next[j])
                    {
                        bool found = search(word, i + 1, curr->next[j]);
                        if (found)
                            return true;
                    }
                return false;
            }
            else if (!curr->next[word[i] - 'a'])
                return false;
            curr = curr->next[word[i] - 'a'];
        }
        return curr->is_leaf;
    }

    TrieNode *root = new TrieNode();
};

class WordDictionary
{
public:
    WordDictionary() { trie = new Trie(); }

    void addWord(string word) { trie->insert(word); }

    bool search(string word) { return trie->search(word, 0, trie->root); }

    Trie *trie;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */