struct TrieNode {
    char val;
    vector<TrieNode*> next;
    bool end;
        
    TrieNode(char v = ' ') {
        val = v;
        next = vector<TrieNode*>(26, NULL);
        end = false;
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* cur = root;
        for (char& c : word) {
            if (!cur->next[c-'a']) cur->next[c-'a'] = new TrieNode(c);
            cur = cur->next[c-'a'];
        }
        cur->end = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchHelper(root, word);
    }
    
private:
    TrieNode* root;
    
    bool searchHelper(TrieNode* t, string word) {
        if (word.empty()) return t->end;
        char c = word[0];
        word = word.substr(1);
        if (c == '.') {
            for (int i=0; i<26; ++i)
                if (t->next[i] && searchHelper(t->next[i], word)) return true;
        }
        else if (t->next[c-'a'])
            return searchHelper(t->next[c-'a'], word);
        return false;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
