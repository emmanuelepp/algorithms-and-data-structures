#include <array>
#include <string>

class TrieNode
{
public:
    std::array<TrieNode *, 26> children = {};
    bool isEndWord = false;

    TrieNode() = default;
};

class Trie
{
private:
    TrieNode *root = new TrieNode();
    int charToIndex(char ch) const
    {
        return ch - 'a';
    }

public:
    Trie() = default;

    void insert(const std::string &word)
    {
        TrieNode *current = root;
        for (char ch : word)
        {
            int index = charToIndex(ch);
            if (current->children[index] == nullptr)
            {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndWord = true;
    }

    // Function to search for a word in the Trie
    bool search(const std::string &word) const
    {
        TrieNode *current = root;
        for (char ch : word)
        {
            int index = charToIndex(ch);
            if (current->children[index] == nullptr)
            {
                return false;
            }
            current = current->children[index];
        }
        return current->isEndWord;
    }

    // Function to check if there is any word in the Trie that starts with a given prefix
    bool startsWith(const std::string &prefix) const
    {
        TrieNode *current = root;
        for (char ch : prefix)
        {
            int index = charToIndex(ch);
            if (current->children[index] == nullptr)
            {
                return false;
            }
            current = current->children[index];
        }
        return true;
    }
};