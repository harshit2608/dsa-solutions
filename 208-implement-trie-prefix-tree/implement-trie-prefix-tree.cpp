class Trie {
private:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;

        bool containsKey(const char& ch) const {
            return children[ch - 'a'] != nullptr;
        }

        void put(const char& ch, TrieNode* node) { children[ch - 'a'] = node; }

        TrieNode* get(const char& ch) const { return children[ch - 'a']; }

        void setEnd() { isEnd = true; }

        bool getEnd() const { return isEnd; }
    };

    TrieNode* root;

    void deleteTrie(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                deleteTrie(node->children[i]);
            }
        }
        delete node;
    }

public:
    Trie() {
        root = new TrieNode();
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    ~Trie() { deleteTrie(root); }

    void insert(const string& word) {
        TrieNode* node = root;
        for (const char& ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool search(const string& word) const {
        TrieNode* node = root;
        for (const char& ch : word) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        return node->getEnd();
    }

    bool startsWith(const string& prefix) const {
        TrieNode* node = root;
        for (const char& ch : prefix) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        return true;
    }
};