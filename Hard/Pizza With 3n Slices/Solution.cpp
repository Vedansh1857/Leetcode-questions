class Solution {
public:
    int solveRec(int index,vector<int>& slices,int endIndex,int n){
        // BASE CASE...
        if(index > endIndex || n == 0) return 0;
        // Take...
        int take = slices[index]+solveRec(index+2,slices,endIndex,n-1);
        // Not Take...
        int notTake = 0 + solveRec(index+1,slices,endIndex,n);
        return max(take,notTake);
    }
    int solveMem(int index,vector<int>& slices,int endIndex,int n,vector<vector<int>>& dp){
        if(index > endIndex || n == 0) return 0;
        if(dp[index][n] != -1) return dp[index][n];
        int take = slices[index] + solveMem(index+2,slices,endIndex,n-1,dp);
        int notTake = 0 + solveMem(index+1,slices,endIndex,n,dp);
        return dp[index][n] =  max(take,notTake);
    }
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();

        // int first = solveRec(0,slices,k-2,k/3);
        // int second = solveRec(1,slices,k-1,k/3);
        // return max(first,second);

        vector<vector<int>> dp1(k+1,vector<int>(k+1,-1));
        vector<vector<int>> dp2(k+1,vector<int>(k+1,-1));
        int first = solveMem(0,slices,k-2,k/3,dp1);
        int second = solveMem(1,slices,k-1,k/3,dp2);
        return max(first,second);
    }
};
