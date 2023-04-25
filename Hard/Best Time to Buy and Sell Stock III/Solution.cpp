class Solution {
public:
// Hard only bcz of one catch which is that we have to use 3D dp in this question...
// First refer to the problem 122 (just previous one) then come to this...
    int solveRec(int index,int buy,vector<int>& prices,int limit){
        // BASE CASE...
        if(index >= prices.size()) return 0;
        if(limit <= 0) return 0; // One additional Base case is added to check whether the limit reached out or not.
        int profit = 0;
        if(buy){
            int buyKaro = -prices[index] + solveRec(index+1,0,prices,limit);
            int skipKaro = 0 + solveRec(index+1,1,prices,limit);
            profit = max(buyKaro,skipKaro);
        }
        else{
            int sellKaro = prices[index] + solveRec(index+1,1,prices,limit-1); // Limit is only decreased whenever the stock is sold after bought.
            int ignoreKaro = 0 + solveRec(index+1,0,prices,limit);
            profit = max(sellKaro,ignoreKaro);
        }
        return profit;
    }
    int solveMem(int index,int buy,vector<int>& prices,int limit,vector<vector<vector<int>>>& dp){
        // BASE CASE...
        if(index >= prices.size()) return 0;
        if(limit <= 0) return 0;
        if(dp[index][buy][limit] != -1) return dp[index][buy][limit];
        int profit = 0;
        if(buy){
            int buyKaro = -prices[index] + solveMem(index+1,0,prices,limit,dp);
            int skipKaro = 0 + solveMem(index+1,1,prices,limit,dp);
            profit = max(buyKaro,skipKaro);
        }
        else{
            int sellKaro = prices[index] + solveMem(index+1,1,prices,limit-1,dp);
            int ignoreKaro = 0 + solveMem(index+1,0,prices,limit,dp);
            profit = max(sellKaro,ignoreKaro);
        }
        return dp[index][buy][limit] = profit;
    }
    int solveTab(vector<int>& prices){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        int  profit = 0;
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=2;limit++){
                    if(buy){
                        int buyKaro = -prices[index] + dp[index+1][0][limit];
                        int skipKaro = 0 + dp[index+1][1][limit];
                        profit = max(buyKaro,skipKaro);
                    }
                    else{
                        int sellKaro = prices[index] + dp[index+1][1][limit-1];
                        int ignoreKaro = 0 + dp[index+1][0][limit];
                        profit = max(sellKaro,ignoreKaro);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        // return solveRec(0,1,prices,2);

        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        // return solveMem(0,1,prices,2,dp);

        return solveTab(prices);
    }
};
