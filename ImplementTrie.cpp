class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(char v = ' ') {
        val = v;
        next = vector<TrieNode*>(26, NULL);
        end = false;
    }
    
    char val;
    vector<TrieNode*> next;
    bool end;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        if (word.empty()) return;
        insertHelper(word, root);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* cur = root;
        for (char& c : word) {
            if (!cur->next[c-'a']) return false;
            cur = cur->next[c-'a'];
        }
        return cur->end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (char& c : prefix) {
            if (!cur->next[c-'a']) return false;
            cur = cur->next[c-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
    
    void insertHelper(string& word, TrieNode* t) {
        char c = word[0];
        if (!t->next[c-'a']) t->next[c-'a'] = new TrieNode(c);
        if (word.size() == 1) {
            t->next[c-'a']->end = true;
            return;
        }
        word = word.substr(1);
        insertHelper(word, t->next[c-'a']);
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
