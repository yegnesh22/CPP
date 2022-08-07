class Solution {
public:
    struct Trie {
            Trie* alphabet[26]  = {nullptr};
            string eow;
    };
    
    void findAllWords(Trie* t, vector<string>& ir) {
        if (ir.size() == 3)
            return;
        
        //cout << "eow : " << t->eow << endl;
        if (!t->eow.empty())
            ir.push_back(t->eow);
        
        for (size_t i = 0; i < 26; i++) {
            Trie* c = t->alphabet[i];
            if (c != nullptr && ir.size() <= 3)
                findAllWords(t->alphabet[i], ir);
        }
        
        return;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        Trie* root = new Trie();
        size_t ps = products.size();
        
        for (size_t i = 0; i < ps; i++) {
            Trie* t = root;
            size_t wl = products[i].length();
            for (size_t j = 0; j < wl; j++) {
                size_t li = products[i][j] - 'a';
                if (t->alphabet[li] == nullptr)
                    t->alphabet[li] = new Trie();
                t = t->alphabet[li];
            }
            t->eow = products[i];
            //cout << "added word " << t->eow << endl;
        }
        
        size_t swl = searchWord.size();
        Trie* t = root;
        for (size_t i = 0; i < swl; i++) {
            size_t li = searchWord[i] - 'a';
            vector<string> ir;
            
            if (t != nullptr)
                t = t->alphabet[li];
            
            if (t != nullptr) {
                if (!t->eow.empty())
                    ir.push_back(t->eow);
                for (size_t j = 0; j < 26; j++) {
                    if (t->alphabet[j] != nullptr) {
                        //cout << (char)(j + 'a') << endl;
                        findAllWords(t->alphabet[j], ir);
                    }
                }
            }
            result.push_back(ir);
        }
        
        return result;
    }
};