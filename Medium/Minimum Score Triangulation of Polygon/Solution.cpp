class Solution {
public:
    int solveRec(vector<int>& a,int i,int j){
        // BASE CASE...
        if(i+1 == j) return 0;
        int ans = INT_MAX;
        for(int k=i+1;k<=j-1;k++) ans = min(ans,a[i]*a[j]*a[k]+solveRec(a,i,k)+solveRec(a,k,j));
        return ans;
    }
    int solveMem(vector<int>& a,int i,int j,vector<vector<int>>& dp){
        // BASE CASE...
        if(i+1 == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k=i+1;k<=j-1;k++) ans = min(ans,a[i]*a[j]*a[k]+solveMem(a,i,k,dp)+solveMem(a,k,j,dp));
        return dp[i][j]=ans;
    }
    int solveTab(vector<int>& a,int i,int j){
        int n = a.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        if(a.size()<=2) return 0;
        for(int i=n-1;i>=0;i--){
            for(int j=i+2;j<n;j++){
                int ans = INT_MAX;
                for(int k=i+1;k<=j-1;k++) ans = min(ans,a[i]*a[j]*a[k]+dp[i][k]+dp[k][j]);
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }
    int minScoreTriangulation(vector<int>& values){
        // int i=0;
        // int j=values.size()-1;
        // return solveRec(values,i,j);

        // int n = values.size();
        // int i=0;
        // int j=values.size()-1;
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solveMem(values,i,j,dp);

        int i=0;
        int j=values.size()-1;
        return solveTab(values,i,j);
    }
};
