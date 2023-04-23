class Solution {
public:
    // Refer to the notes of this problem for intuition...
    int solveRec(int start,int end){
        // BASE CASE...
        if(start >= end) return 0;
        int ans = INT_MAX;
        for(int i=start;i<=end;i++) ans = min(ans,i+max(solveRec(start,i-1),solveRec(i+1,end)));
        return ans;
    }
    int solveMem(int start,int end,vector<vector<int>>& dp){
        // BASE CASE...
        if(start >= end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int ans = INT_MAX;
        for(int i=start;i<=end;i++) ans = min(ans,i+max(solveMem(start,i-1,dp),solveMem(i+1,end,dp)));
        return dp[start][end] = ans;
    }
    int getMoneyAmount(int n) {
        // return solveRec(1,n);

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solveMem(1,n,dp);
    }
};
