class Solution {
public:
    void dfs(vector<vector<char>>& grid,int r,int c)
    {
        int m=grid.size();
        int n=grid[0].size();
        grid[r][c]=0;
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,1,-1};
        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0&& nr<m && nc>=0 && nc<n && grid[nr][nc]=='1')
             dfs(grid,nr,nc);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                 {
                    count++;
                    dfs(grid,i,j);
                 }
            }
        }
        return count;
        
        
    }
};