class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        queue<pair<int,int>> q;
        if(grid[0][0]==1||grid[m-1][m-1]==1)
         return -1;
        q.push({0,0});
        int dr[8] = {-1,-1,-1,0,0,1,1,1};
        int dc[8] = {-1,0,1,-1,1,-1,0,1};
        int distance=1;
        while(!q.empty())
        {
           int s=q.size();
           for(int i=0;i<s;i++)
           {
              auto[r,c]=q.front();
              q.pop();
              if(r==m-1 && c==m-1)
               return distance;
              for(int i=0;i<8;i++)
             {
                int nr=dr[i]+r;
                int nc=dc[i]+c;
                if(nr>=0 && nr<m && nc>=0 && nc<m && grid[nr][nc]==0)
                 {
                  grid[nr][nc]=1;
                  q.push({nr,nc});
                 }
           }
           }
           distance++;
           
        }
        return -1;
        
    }
};