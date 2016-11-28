class Trie{
public:
    vector<Trie*> children;
    bool wholeWord;
    Trie(){
        children = vector<Trie*>(26, NULL);
        wholeWord = false;
    }
};

class WordDictionary {
private:
    Trie* root;
public:
    WordDictionary(){
        root = new Trie();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        Trie* p = root;
        for(char c : word){
            int idx = c - 'a';
            if(p->children[idx] == NULL) p->children[idx] = new Trie();
            p = p->children[idx];
        }
        p->wholeWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool _search(Trie* p, string word, int idx){
        if(p == NULL) return false;
        if(idx == word.length()) return p->wholeWord;
        if(word[idx] == '.'){
            for(Trie* child : p->children){
                if(_search(child, word, idx+1)) return true;
            }
        }else{
            return _search(p->children[word[idx] - 'a'], word, idx+1);
        }
        return false;
    }
    bool search(string word) {
        if(word.empty()) return false;
        return _search(root, word, 0);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
