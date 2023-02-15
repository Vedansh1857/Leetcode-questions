class Solution {
public:
    int numSquares(int n) {
        if(n==0) return 0;
	    if(n==1) return 1;
	    vector<int> dp(n+1);
	    dp[0] = 0;
	    dp[1] = 1;
	    for(int i=2;i<=n;i++){
	        int mini = INT_MAX;
	        for(int j=1;j*j<=i;j++){
	            int val = i-(j*j);
	            mini = min(mini,dp[val]);
	        }
	        dp[i]=mini+1;
	    }
	    return dp[n];
    }
};
