class WordDictionary {
public:
    
    struct Node {
        Node* links[26];
        bool isEnd = false;
    };
    
    Node* root;
    
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        
        for(char c : word){
            int idx = c - 'a';
            
            if(node->links[idx] == NULL){
                node->links[idx] = new Node();
            }
            
            node = node->links[idx];
        }
        
        node->isEnd = true;
    }
    
    bool dfs(string word, int i, Node* node){
        
        if(i == word.size()){
            return node->isEnd;
        }
        
        if(word[i] == '.'){
            for(int j = 0; j < 26; j++){
                if(node->links[j] && dfs(word, i+1, node->links[j])){
                    return true;
                }
            }
            return false;
        }
        else{
            int idx = word[i] - 'a';
            
            if(node->links[idx] == NULL){
                return false;
            }
            
            return dfs(word, i+1, node->links[idx]);
        }
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};