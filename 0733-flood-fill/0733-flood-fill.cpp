class Solution {
public:
   void dfs(int r,int c,vector<vector<int>>& image,int original,int color)
   {
    int m=image.size();
    int n=image[0].size();
    image[r][c]=color;
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    for(int i=0;i<4;i++)
    {
        int nr=r+dr[i];
        int nc=c+dc[i];
        if(nr>=0 && nr<m && nc>=0 && nc<n && image[nr][nc]==original)
         dfs(nr,nc,image,original,color);
    }
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original=image[sr][sc];
        if(original==color)
         return image;
        dfs(sr,sc,image,original,color);
        return image;
        

        
    }
};