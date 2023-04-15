class Solution {
public:
    int solveRec(vector<int>& sat,int index,int time){
        // BASE CASE...
        if(index >= sat.size()) return 0;
        int incl = sat[index]*(time+1) + solveRec(sat,index+1,time+1);
        int excl = 0 + solveRec(sat,index+1,time);
        int ans = max(incl,excl);
        return ans;
    }
    int solveMem(vector<int>& sat,int index,int time,vector<vector<int>>& dp){
        // BASE CASE...
        if(index >= sat.size()) return 0;
        if(dp[index][time] != -1) return dp[index][time];
        int incl = sat[index]*(time+1) + solveMem(sat,index+1,time+1,dp);
        int excl = 0 + solveMem(sat,index+1,time,dp);
        dp[index][time] = max(incl,excl);
        return dp[index][time];
    }
    int solveTab(vector<int>& sat){
        int n = sat.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int index=n-1;index>=0;index--){
            for(int time=index;time>=0;time--){
                int incl = sat[index]*(time+1) + dp[index+1][time+1];
                int excl = 0 + dp[index+1][time];
                dp[index][time] = max(incl,excl);
            }
        }
        return dp[0][0];
    }
    int maxSatisfaction(vector<int>& satisfaction){
        sort(satisfaction.begin(),satisfaction.end()); // We sort first bcz to get the maximum ans we need to multiply the maximum value of the array with the max time
        // return solveRec(satisfaction,0,0);

        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solveMem(satisfaction,0,0,dp);

        return solveTab(satisfaction);
    }
};
