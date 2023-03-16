class Solution {
public:
    int solveRec(int i,int j,vector<vector<int>>& triangle){
        if(triangle.size() == i) return 0;
        if(triangle.size() == 1) return triangle[0][0];
        return min(solveRec(i+1,j,triangle),solveRec(i+1,j+1,triangle)) + triangle[i][j];
    }
    int solveMem(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(triangle.size() == i) return 0;
        if(triangle.size() == 1) return triangle[0][0];
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = min(solveMem(i+1,j,triangle,dp),solveMem(i+1,j+1,triangle,dp)) + triangle[i][j];
        return dp[i][j];
    }
    int solveTab(int n,int m,vector<vector<int>>& triangle){
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<m;i++) dp[n-1][i] = triangle[n-1][i];
        for(int j=m-2;j>=0;j--){
            for(int k=j;k>=0;k--){
                dp[j][k] = min(dp[j+1][k],dp[j+1][k+1]) + triangle[j][k];
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle){
        // return solveRec(0,0,triangle);

        // int n = triangle.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return solveMem(0,0,triangle,dp);
        // Arguments are 0,0 bcz it is a top-down approach.So, we will start frm the top i.e.triangle[0].

        int n = triangle.size();
        int m = triangle[n-1].size();
        return solveTab(n,m,triangle);
        // Arguments are n,m bcz it is a bottum-up approach.So,we will start frm the bottom.
    }
};
