class TrieNode {
public:
    // Initialize your data structure here.
    vector<TrieNode*> children;
    bool isWord;
    TrieNode() {
        children = vector<TrieNode*>(26, NULL);
        isWord = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* node = root;
        for(auto c : word){
            int idx = c - 'a';
            if(node->children[idx] == NULL){
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root;
        for(auto c : word){
            int idx = c - 'a';
            if(node->children[idx] == NULL) return false;
            node = node->children[idx];
        }
        return node->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(auto c : prefix){
            int idx = c - 'a';
            if(node->children[idx] == NULL) return false;
            node = node->children[idx];
        }
        return node != NULL;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
