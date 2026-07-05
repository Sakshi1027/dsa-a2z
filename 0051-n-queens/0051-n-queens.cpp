class Solution {
public:
    bool isSafe(int row,int col,vector<string>& board,int n)
    {
        for(int i=0;i<row;i++)
        {
            if(board[i][col]=='Q')
             return false;
        }
        int i=row;
        int j=col;
        while(i>=0 && j>=0)
        {
            if(board[i][j]=='Q')
             return false;
            i--;
            j--;
        }
        i=row;
        j=col;
        while(i>=0 && j<=n)
        {
            if(board[i][j]=='Q')
             return false;
            i--;
            j++;
            

        }
     return true;

    }
    void solve(int row,
           vector<string>& board,
           vector<vector<string>>& ans,
           int n)
{
    // Base Case
    if(row == n)
    {
        ans.push_back(board);
        return;
    }

    // Try every column
    for(int col = 0; col < n; col++)
    {
        // Check if it's safe
        if(isSafe(row, col, board, n))
        {
            // Choose
            board[row][col] = 'Q';

            // Explore
            solve(row + 1, board, ans, n);

            // Undo (Backtrack)
            board[row][col] = '.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        solve(0,board,ans,n);
        return ans;
        
    }
};