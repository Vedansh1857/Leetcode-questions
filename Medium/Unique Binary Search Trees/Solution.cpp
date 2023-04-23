class Solution {
public:
    int solveRec(int n){
        // BASE CASE...
        if(n == 1 || n == 0) return 1; // When there is only one or no node then there is only one way.
        if(n == 2) return 2; // When there are only two nodes no. of ways are 2 only.
        int ans = 0;
        // Here in the loop i is the root node. So, each number till n is a root at a tym and we call recursion for numbers before i (i-1) and after i (n-i) to get the no.of ways
        for(int i=1;i<=n;i++) ans += solveRec(i-1) * solveRec(n-i);
        return ans;
    }
    int solveMem(int n,vector<int>& dp){
        // BASE CASE...
        if(n == 1 || n == 0) return 1;
        if(n == 2) return 2;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for(int i=1;i<=n;i++) ans += solveMem(i-1,dp) * solveMem(n-i,dp);
        return dp[n] = ans;
    }
    int numTrees(int n){
        // return solveRec(n);

        vector<int> dp(n+1,-1);
        return solveMem(n,dp);
    }
};
