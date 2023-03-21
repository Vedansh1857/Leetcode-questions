//User function Template for C++

class Solution{
	public:
	int solveRec(int n){
	   // Base case...
	   if(n==0) return 0;
	   int ans = INT_MAX;
	   for(int i=1;i<=sqrt(n);i++){
	       ans = min(ans , solveRec(n-i*i)+1);
	   }
	   return ans;
	}
	int solveMem(int n,vector<int>& dp){
	   // Base case...
	   if(n==0) return 0;
	   if(dp[n] != -1) return dp[n];
	   int ans = INT_MAX;
	   for(int i=1;i<=sqrt(n);i++){
	       ans = min(ans , solveMem(n-i*i,dp)+1);
	   }
	   dp[n] = ans;
	   return dp[n];
	}
	int solveTab(int n){
	    vector<int> dp(n+1,INT_MAX);
	    dp[0] = 0;
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sqrt(n);j++){
	            if(i-j*j>=0) dp[i] = min(dp[i] , dp[i-j*j]+1);
	        }
	    }
	    return dp[n];
	}
	int MinSquares(int n){
	    // Code here
	    // return solveRec(n);
	   
	    // vector<int> dp(n+1,-1);
	    // return solveMem(n,dp);
	    
	    return solveTab(n);
	}
};
