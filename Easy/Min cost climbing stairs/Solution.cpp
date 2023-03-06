class Solution {
public:

    // For recursion...
    int solve(vector<int>& cost,int n){
        // Base case...
        if(n==1) return cost[1];
        if(n==0) return cost[0];

        int ans = cost[n] + min(solve(cost,n-1) , solve(cost,n-2));
        return ans;
    }

    // For recursion + Memoization...(Top-down approach)
    int solve2(vector<int>& cost,int n,vector<int>& dp){
        // Base case...
        if(n==1) return cost[1];
        if(n==0) return cost[0];

        // Check if the ans of the particular case is already stored in the dp array(Step 3)
        if(dp[n] != -1) return dp[n];

        // Storing the ans in the dp array & returning it(Step 2)
        dp[n] = cost[n] + min(solve2(cost,n-1,dp) , solve2(cost,n-2,dp));
        return dp[n];
    }

    // For Tabulation method...(Bottom-up approach)
    int solve3(vector<int>& cost,int n){
        // Creating our dp array...(Step1)
        vector<int> dp(n+1);

        // Initializing first two base cases in our dp array...(Step 2)
        dp[0] = cost[0];
        dp[1] = cost[1];

        // Looping after the zeroth & first index...(Step 3)
        for(int i=2;i<n;i++){
            dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }

    // Finally Space optimization...
    int solve4(vector<int>& cost,int n){

        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i=2;i<n;i++){
            int curr = cost[i] + min(prev2,prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev2,prev1);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // // Driver code for recursive approach...
        // int n = cost.size();
        // int ans = min(solve(cost,n-1) , solve(cost,n-2));
        // return ans;

        // // Driver code for recursion + Memoization...(Top-down approach)...
        // int n = cost.size();
        // // Step 1 for solve2 functions...
        // vector<int> dp(n+1,-1);
        // int ans = min(solve2(cost,n-1,dp) , solve2(cost,n-2,dp));
        // return ans;

        // // Driver code for Tabulation method...(Bottom-up approach)...
        // int n = cost.size();
        // int ans = solve3(cost,n);
        // return ans;

        // Driver code for the space optimization function...
        int n = cost.size();
        int ans = solve4(cost,n);
        return ans;
    }
};
