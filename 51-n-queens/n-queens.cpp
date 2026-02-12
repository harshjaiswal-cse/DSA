class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<string> board(n, string(n, '.'));
        
        // Sets to track occupied columns and diagonals
        // Using unordered_set for O(1) average lookup
        unordered_set<int> cols;
        unordered_set<int> posDiag; // (r + c)
        unordered_set<int> negDiag; // (r - c)

        backtrack(0, n, board, results, cols, posDiag, negDiag);
        return results;
    }

private:
    void backtrack(int r, int n, vector<string>& board, vector<vector<string>>& results,
                   unordered_set<int>& cols, unordered_set<int>& posDiag, unordered_set<int>& negDiag) {
        // Base case: All queens are placed
        if (r == n) {
            results.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            // Check if the current position (r, c) is under attack
            if (cols.count(c) || posDiag.count(r + c) || negDiag.count(r - c)) {
                continue;
            }

            // "Choose" - Place the queen
            board[r][c] = 'Q';
            cols.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);

            // "Explore" - Move to the next row
            backtrack(r + 1, n, board, results, cols, posDiag, negDiag);

            // "Un-choose" - Backtrack and clean up
            board[r][c] = '.';
            cols.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
        }
    }
};