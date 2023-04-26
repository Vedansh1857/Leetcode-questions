class Solution {
public:
    int solveRec(int r,int d,int m,int n,vector<vector<int>>& obstacleGrid){
        // BASE CASE...
        if(r >= m || d >= n || obstacleGrid[r][d]==1) return 0;
        if(r==m-1 && d==n-1) return 1;
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        int right = 0;
        if(obstacleGrid[r][d] != 1) right = solveRec(r+1,d,m,n,obstacleGrid);
        int down = 0;
        if(obstacleGrid[r][d] != 1) down = solveRec(r,d+1,m,n,obstacleGrid);
        return right+down;
    }
    int solveMem(int r,int d,int m,int n,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        // BASE CASE...
        if(r >= m || d >= n || obstacleGrid[r][d]==1) return 0;
        if(r==m-1 && d==n-1) return 1;
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        if(dp[r][d] != -1) return dp[r][d];
        int right = 0;
        if(obstacleGrid[r][d] != 1) right = solveMem(r+1,d,m,n,obstacleGrid,dp);
        int down = 0;
        if(obstacleGrid[r][d] != 1) down = solveMem(r,d+1,m,n,obstacleGrid,dp);
        return dp[r][d] = right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // return solveRec(0,0,m,n,obstacleGrid);

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solveMem(0,0,m,n,obstacleGrid,dp);
    }
};
