class Solution {
public:
    int solveRec(vector<int>& obs,int n,int curr_lane,int curr_pos){
        // BASE CASE...
        if(curr_pos == n-1) return 0;
        // When there is no obstacle in the lane the frog is currently moving...
        if(obs[curr_pos+1] != curr_lane) return solveRec(obs,n,curr_lane,curr_pos+1);
        // When frog has to perform sideways jump...
        int ans = INT_MAX;
        for(int i=1;i<=3;i++){
            if(i!=curr_lane && obs[curr_pos]!=i) // Sideways jumps are only possible from current lane to any different lanes.
            ans = min(ans,1+solveRec(obs,n,i,curr_pos)); // Here "i" indicates the lane no.
        }
        return ans;
    }
    int solveMem(vector<int>& obs,int n,int curr_lane,int curr_pos,vector<vector<int>>& dp){
        // BASE CASE...
        if(curr_pos == n-1) return 0;
        if(dp[curr_lane][curr_pos] != -1) return dp[curr_lane][curr_pos];
        if(obs[curr_pos+1] != curr_lane) return solveMem(obs,n,curr_lane,curr_pos+1,dp);
        int ans = INT_MAX;
        for(int i=1;i<=3;i++){
            if(i!=curr_lane && obs[curr_pos]!=i) // Sideways jumps are only possible from current lane to any different lanes.
            ans = min(ans,1+solveMem(obs,n,i,curr_pos,dp)); // Here "i" indicates the lane no.
        }
        return dp[curr_lane][curr_pos] = ans;
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        // return solveRec(obstacles,n,2,0);

        vector<vector<int>>dp(4,vector<int>(n+2,-1));
        return solveMem(obstacles,n,2,0,dp);
    }
};
