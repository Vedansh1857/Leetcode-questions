class Solution {
public:
int solveRec(int n){
	  if(n<0) return 0;
		if(n==0) return 1;
		int ans = 1+solveRec(n-2);
		return ans;
	}
	int solveMem(int n,vector<int>& dp){
	    if(n<0) return 0;
		if(n==0) return 1;
		if(n==3) return 3;
		if(dp[n] != -1) return dp[n];
		return dp[n] = solveMem(n-1,dp)+solveMem(n-2,dp);
	}
    int climbStairs(int n) {
    // return solveRec(n);
	   vector<int> dp(n+1,-1);
	   return solveMem(n,dp);
	   // return (n/2) + 1;
    }
};
