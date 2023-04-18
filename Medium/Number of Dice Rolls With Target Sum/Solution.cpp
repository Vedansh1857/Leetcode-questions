class Solution {
public:
	int mod=1e9+7;
	int f(int i,int tar,int k,int n,vector<vector<int>>& dp){
		if(i==n){
			if(!tar) return 1;
			return 0;
		}    
		if(dp[i][tar]!=-1) return dp[i][tar];
		long long p=0;
		for(int j=1;j<=k;j++){
			if(tar>=j) p+=f(i+1,tar-j,k,n,dp)%mod;
		}
		return dp[i][tar]=p%mod;
	}
	int numRollsToTarget(int n, int k, int tar) {
		vector<vector<int>> dp(n,vector<int>(tar+1,-1));
		return f(0,tar,k,n,dp)%mod;
	}
};
