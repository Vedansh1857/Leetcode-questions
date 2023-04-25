class Solution {
public:
// Read the notes of it for better understanding...
    int solveRec(int index,int buy,vector<int>& prices){
        // BASE CASE...
        if(index >= prices.size()) return 0;
        int profit = 0;
        if(buy){
            int buyKaro = -prices[index] + solveRec(index+1,0,prices);
            int skipKaro = 0 + solveRec(index+1,1,prices);
            profit = max(buyKaro,skipKaro);
        }
        else{
            int sellKaro = prices[index] + solveRec(index+1,1,prices);
            int ignoreKaro = 0 + solveRec(index+1,0,prices);
            profit = max(sellKaro,ignoreKaro);
        }
        return profit;
    }
    int solveMem(int index,int buy,vector<int>& prices,vector<vector<int>>& dp){
        // BASE CASE...
        if(index >= prices.size()) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        int profit = 0;
        if(buy){
            int buyKaro = -prices[index] + solveMem(index+1,0,prices,dp);
            int skipKaro = 0 + solveMem(index+1,1,prices,dp);
            profit = max(buyKaro,skipKaro);
        }
        else{
            int sellKaro = prices[index] + solveMem(index+1,1,prices,dp);
            int ignoreKaro = 0 + solveMem(index+1,0,prices,dp);
            profit = max(sellKaro,ignoreKaro);
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        // return solveRec(0,1,prices);

        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solveMem(0,1,prices,dp);
    }
};
