class Solution {
public:
    bool solveRec(int index,vector<int>& nums,int n,int t){
        // BASE CASE...
        if(index >= n) return 0;
        if(t < 0) return 0;
        if(t == 0) return 1;
        // Take...
        bool incl = solveRec(index+1,nums,n,t-nums[index]);
        // Not take...
        bool excl = solveRec(index+1,nums,n,t);
        return incl or excl;
    }
    bool solveMem(int index,vector<int>& nums,int n,int t,vector<vector<int>>& dp){
        // BASE CASE...
        if(index >= n) return 0;
        if(t < 0) return 0;
        if(t == 0) return 1;
        if(dp[index][t] != -1) return dp[index][t];
        // Take...
        bool incl = solveMem(index+1,nums,n,t-nums[index],dp);
        // Not take...
        bool excl = solveMem(index+1,nums,n,t,dp);
        return dp[index][t] = incl or excl;
    }
    bool canPartition(vector<int>& nums){
        auto sum = accumulate(nums.begin(),nums.end(),0);
        int target = sum/2;
        int n = nums.size();
        if(sum%2!=0) return 0;
        // return solveRec(0,nums,n,target);

        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solveMem(0,nums,n,target,dp);
    }
};
