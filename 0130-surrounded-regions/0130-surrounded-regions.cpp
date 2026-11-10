class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col) {
        int m = board.size();
        int n = board[0].size();

        board[row][col] = '#';

        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++) {

            int nr = row + delrow[i];
            int nc = col + delcol[i];

            if(nr >= 0 && nr < m &&
               nc >= 0 && nc < n &&
               board[nr][nc] == 'O') {

                dfs(board, nr, nc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if(board[i][n-1] == 'O') {
                dfs(board, i, n-1);
            }
        }

        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O') {
                dfs(board, 0, j);
            }
            if(board[m-1][j] == 'O') {
                dfs(board, m-1, j);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if (board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }

    }
};