class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       unordered_set<int>zeroRows,zeroCols;
       int n=matrix.size();
       int m=matrix[0].size();
       for(int i=0;i<n;i++)
       {
         for(int j=0;j<m;j++)
         {
            if(matrix[i][j]==0)
             {
                zeroRows.insert(i);
                zeroCols.insert(j);
             }
         }
       } 
        for(int i=0;i<n;i++)
       {
         for(int j=0;j<m;j++)
         {
            if(zeroRows.count(i)||zeroCols.count(j))
             {
                matrix[i][j]=0;
             }
         }
       }
    }
};