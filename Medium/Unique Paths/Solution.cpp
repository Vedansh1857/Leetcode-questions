class Solution {
public:
    int solveRec(int r,int d,int m,int n){
        // BASE CASE...
        if(r==m-1 && d==n-1) return 1;
        if(r >= m || d >= n) return 0;   
        int ans = solveRec(r+1,d,m,n)+solveRec(r,d+1,m,n);
        return ans;
    }
    int solveMem(int r,int d,int m,int n,vector<vector<int>>& dp){
        // BASE CASE...
        if(r==m-1 && d==n-1) return 1;
        if(r >= m || d >= n) return 0;   
        if(dp[r][d] != -1) return dp[r][d];
        int ans = solveMem(r+1,d,m,n,dp)+solveMem(r,d+1,m,n,dp);
        return dp[r][d] = ans;
    }
    int uniquePaths(int m, int n){
        //   return solveRec(0,0,m,n);
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solveMem(0,0,m,n,dp);
    }
};
