class TrieNode {
public:
    TrieNode* children[26];
    string word;

    TrieNode() {
        word = "";
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Solution {
public:

    vector<string> result;

    void insert(TrieNode* root, string word) {

        TrieNode* node = root;

        for(char c : word) {

            int idx = c - 'a';

            if(node->children[idx] == nullptr)
                node->children[idx] = new TrieNode();

            node = node->children[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board,
             int r,
             int c,
             TrieNode* node) {

        char ch = board[r][c];

        if(ch == '#' || node->children[ch - 'a'] == nullptr)
            return;

        node = node->children[ch - 'a'];

        if(node->word != "") {
            result.push_back(node->word);
            node->word = "";
        }

        board[r][c] = '#';

        int dirs[4][2] = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        for(auto &d : dirs) {

            int nr = r + d[0];
            int nc = c + d[1];

            if(nr >= 0 &&
               nr < board.size() &&
               nc >= 0 &&
               nc < board[0].size()) {

                dfs(board, nr, nc, node);
            }
        }

        board[r][c] = ch;
    }

    vector<string> findWords(
        vector<vector<char>>& board,
        vector<string>& words) {

        TrieNode* root = new TrieNode();

        for(string word : words)
            insert(root, word);

        for(int i = 0; i < board.size(); i++) {

            for(int j = 0; j < board[0].size(); j++) {

                dfs(board, i, j, root);
            }
        }

        return result;
    }
};