class Solution {
public:
     int solve(int row,int col,
           vector<vector<int>>& grid,int m,int n,vector<vector<int>>& visited)
{
    if(row<0 || row>=m || col<0 || col>=n)
        return 0;

    if(visited[row][col])
        return 0;

    if(grid[row][col]==0)
        return 0;

    visited[row][col]=true;

    int down=solve(row+1,col,grid,m,n,visited);
    int left=solve(row,col-1,grid,m,n,visited);
    int right=solve(row,col+1,grid,m,n,visited);
    int up=solve(row-1,col,grid,m,n,visited);

    visited[row][col]=false;
    return grid[row][col]+max({down,left,right,up});
}
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0)
                 ans=max(ans,solve(i,j,grid,m,n,visited));
            }
        }
        return ans;

        
    }
};