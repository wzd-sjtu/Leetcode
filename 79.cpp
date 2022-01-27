class Solution {
public:
    // 对于每一个开始的位置
    int m;
    int n;
    bool is_ok_loc(int i, int j) {
        if(i>=0 && j>=0 && i<m && j<n) return true;
        return false;
    }
    bool is_find;
    string myword;
    int word_size;

    void dfs(int i, int j, int loc, vector<vector<char>>& board, vector<vector<int>>& is_visited) {

        // when to stop the location is important
        if(loc == word_size) {
            is_find = true;
            return;
        }

        if(is_find) return;
        if(!is_ok_loc(i, j)) return;
        if(is_visited[i][j]) return;


        if(board[i][j] == myword[loc]) {
            is_visited[i][j] = 1; // shows have been visited

            dfs(i+1, j, loc + 1, board, is_visited);
            dfs(i, j+1, loc + 1, board, is_visited);
            dfs(i-1, j, loc + 1, board, is_visited);
            dfs(i, j-1, loc + 1, board, is_visited);

            is_visited[i][j] = 0;
        }

        return;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        // 一个全局标记，加一个全区isvisited，做dfs即可完成
        m = board.size();
        n = board[0].size();
        is_find = false;
        myword = word;
        word_size = word.size();

        vector<vector<int>> is_visited(m, vector<int>(n, 0));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(is_find) return true;
                dfs(i, j, 0, board, is_visited);
            }
        }
        return is_find;
    }
};