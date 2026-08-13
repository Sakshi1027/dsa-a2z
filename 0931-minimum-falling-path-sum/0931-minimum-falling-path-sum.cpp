class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // First row
        for(int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Remaining rows
        for(int i = 1; i < m; i++) {

            for(int j = 0; j < n; j++) {

                int best = dp[i-1][j];

                if(j > 0)
                    best = min(best, dp[i-1][j-1]);

                if(j < n-1)
                    best = min(best, dp[i-1][j+1]);

                dp[i][j] = matrix[i][j] + best;
            }
        }

        // Minimum in last row
        int ans = INT_MAX;

        for(int j = 0; j < n; j++) {
            ans = min(ans, dp[m-1][j]);
        }

        return ans;
    }
};