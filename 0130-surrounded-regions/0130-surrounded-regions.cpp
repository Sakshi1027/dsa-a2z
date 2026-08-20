class Solution {
public:

    void dfs(vector<vector<char>>& board, int r, int c) {

        int m = board.size();
        int n = board[0].size();

        // Mark this O as safe
        board[r][c] = 'T';

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for(int k = 0; k < 4; k++) {

            int nr = r + dr[k];
            int nc = c + dc[k];

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

        // Top and bottom boundaries
        for(int j = 0; j < n; j++) {

            if(board[0][j] == 'O')
                dfs(board, 0, j);

            if(board[m-1][j] == 'O')
                dfs(board, m-1, j);
        }

        // Left and right boundaries
        for(int i = 0; i < m; i++) {

            if(board[i][0] == 'O')
                dfs(board, i, 0);

            if(board[i][n-1] == 'O')
                dfs(board, i, n-1);
        }

        // Convert surrounded O's to X
        // Convert safe T's back to O
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == 'O')
                    board[i][j] = 'X';

                else if(board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
};