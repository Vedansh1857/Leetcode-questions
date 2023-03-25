class Solution {
public:
    int solveRec(vector<int>& days, vector<int>& costs,int index){
        // BASE CASE...
        int n = days.size();
        if(index>=n) return 0;
        int dayOne = costs[0]+solveRec(days,costs,index+1);

        int i;
        for(i=index ; i<n && days[i]<days[index]+7 ; i++); int daySeven = costs[1] + solveRec(days,costs,i);

        int j;
        for(j=index ; j<n && days[j]<days[index]+30 ; j++); int dayThirty = costs[2] + solveRec(days,costs,j);

        int ans = min(dayOne,min(daySeven,dayThirty));
        return ans;
    }
    int solveMem(vector<int>& days, vector<int>& costs,int index,vector<int>& dp){
        // BASE CASE...
        int n = days.size();
        if(index>=n) return 0;
        if(dp[index] != -1) return dp[index];
        int dayOne = costs[0]+solveMem(days,costs,index+1,dp);

        int i;
        for(i=index ; i<n && days[i]<days[index]+7 ; i++); int daySeven = costs[1] + solveMem(days,costs,i,dp);

        int j;
        for(j=index ; j<n && days[j]<days[index]+30 ; j++); int dayThirty = costs[2] + solveMem(days,costs,j,dp);

        int ans = min(dayOne,min(daySeven,dayThirty));
        return dp[index] = ans;
    }
    int solveTab(vector<int>& days, vector<int>& costs){
        int n = days.size();
        vector<int> dp(n+1,0);
        dp[n] = 0;
        for(int k=n-1;k>=0;k--){
            int dayOne = costs[0]+dp[k+1];

            int i;
            for(i=k ; i<n && days[i]<days[k]+7 ; i++); int daySeven = costs[1] + dp[i];

            int j;
            for(j=k ; j<n && days[j]<days[k]+30 ; j++); int dayThirty = costs[2] + dp[j];

            dp[k] = min(dayOne,min(daySeven,dayThirty));
        }
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return solveRec(days,costs,0);

        // int n = days.size();
        // vector<int> dp(n+1,-1);
        // return solveMem(days,costs,0,dp);

        return solveTab(days,costs);
    }
};
