class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> rowUsed(n, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);
        solve(0, n, board, ans,
              rowUsed, upperDiagonal, lowerDiagonal);
        return ans;
    }

    void solve(int col, int n,
               vector<string>& board,
               vector<vector<string>>& ans,
               vector<int>& rowUsed,
               vector<int>& upperDiagonal,
               vector<int>& lowerDiagonal) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {

            if (rowUsed[row] ||
                upperDiagonal[n - 1 + col - row] ||
                lowerDiagonal[row + col]) {
                continue;
            }
            board[row][col] = 'Q';
            rowUsed[row] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            lowerDiagonal[row + col] = 1;

            solve(col + 1, n, board, ans,
                  rowUsed, upperDiagonal, lowerDiagonal);

            board[row][col] = '.';
            rowUsed[row] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
            lowerDiagonal[row + col] = 0;
        }
    }
};