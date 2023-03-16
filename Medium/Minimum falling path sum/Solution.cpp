class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row,vector<int>(col,0));
        for(int m=0;m<col;m++) dp[0][m] = matrix[0][m];
        for(int i=1;i<row;i++){
            for(int j=0;j<col;j++){
                if(j==0) dp[i][j] = min(dp[i-1][j] , dp[i-1][j+1]) + matrix[i][j];
                else if(j==col-1) dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]) + matrix[i][j];
                else dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1])) + matrix[i][j];
            }
        }
        int maxi = INT_MAX;
        for(int k=0;k<col;k++){
            maxi = min(maxi,dp[col-1][k]);
        }
        return maxi;
    }
};
