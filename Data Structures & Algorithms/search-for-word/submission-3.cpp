class Solution {
public:
    void backtrack(
        int row,
        int col,
        string word,
        int idx,
        vector<vector<char>>& board,
        vector<vector<bool>>& visited,
        bool& res
    ) {
        if (res) return;

        if (
            row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size() ||
            visited[row][col] ||
            board[row][col] != word[idx]
        ) {
            return;
        }

        visited[row][col] = true;
        idx++;

        if (idx == word.size()) {
            res = true;
            visited[row][col] = false;
            return;
        }

        if (col + 1 < board[0].size()) {
            // cout << "moving right" << endl;
            backtrack(row, col + 1, word, idx, board, visited, res);
        }

        if (col - 1 >= 0) {
            // cout << "moving left" << endl;
            backtrack(row, col - 1, word, idx, board, visited, res);
        }

        if (row + 1 < board.size()) {
            // cout << "moving down" << endl;
            backtrack(row + 1, col, word, idx, board, visited, res);
        }

        if (row - 1 >= 0) {
            // cout << "moving up" << endl;
            backtrack(row - 1, col, word, idx, board, visited, res);
        }

        visited[row][col] = false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;

        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                backtrack(row, col, word, 0, board, visited, res);
                if (res) return true;
            }
        }

        return false;
    }
};