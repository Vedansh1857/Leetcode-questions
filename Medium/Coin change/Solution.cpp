class Solution {
public:
    int solveRec(vector<int>& coins , int amount){
        // Base case...
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        int mini = INT_MAX;
        for(int i : coins){
            int ans = solveRec(coins,amount-i);
            if(ans != INT_MAX) mini = min(mini,1+ans);
        }
        return mini;
    }
    int solveMem(vector<int>& coins , int amount , vector<int>& dp){
        // Base case...
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        // Step 3...
        if(dp[amount] != -1) return dp[amount];

        int mini = INT_MAX;
        for(int i : coins){
            int ans = solveRec(coins,amount-i);
            if(ans != INT_MAX) mini = min(mini,1+ans);
        }
        // Step 2...
        return dp[amount] = mini;
    }
    int solveTab(vector<int>& coins , int amount){
        vector<int> dp(amount+1 , INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j : coins){
                if(i-j >= 0 && dp[i-j] != INT_MAX) dp[i] = min(dp[i],1+dp[i-j]);
            }
        }
        return (dp[amount]==INT_MAX) ? -1:dp[amount];
    }
    int coinChange(vector<int>& coins, int amount){
        // int ans1 = solveRec(coins,amount);
        // if(ans1 == INT_MAX) return -1;
        // else return ans1;

        // // Step 1 of solveMem function...
        // vector<int> dp(amount+1 , -1);
        // int ans = solveMem(coins,amount,dp);
        // return (ans==INT_MAX) ? -1:ans;
        return solveTab(coins,amount);
    }
};
