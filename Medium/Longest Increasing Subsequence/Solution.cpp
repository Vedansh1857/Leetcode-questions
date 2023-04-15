class Solution {
public:
    int solveRec(int n,vector<int>& nums,int curr,int prev){
        // BASE CASE...
        if(curr == n) return 0;
        // Include...
        int incl = 0;
        if(prev == -1 || nums[curr]>nums[prev]) incl = 1 + solveRec(n,nums,curr+1,curr);
        // Exclude...
        int excl = 0 + solveRec(n,nums,curr+1,prev);
        return max(incl,excl);
    }
    int solveMem(int n,vector<int>& nums,int curr,int prev,vector<vector<int>>& dp){
        // BASE CASE...
        if(curr == n) return 0;
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        int incl = 0;
        if(prev == -1 || nums[curr]>nums[prev]) incl = 1 + solveMem(n,nums,curr+1,curr,dp);
        int excl = 0 + solveMem(n,nums,curr+1,prev,dp);
        return dp[curr][prev+1] = max(incl,excl);
    }
    int solveTab(int n,vector<int>& nums){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int curr = n-1;curr>=0;curr--){
            for(int prev = n-1;prev>=-1;prev--){
                int incl = 0;
                if(prev == -1 || nums[curr]>nums[prev]) incl = 1 + dp[curr+1][curr+1];
                int excl = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(incl,excl);
            }
        }
        return dp[0][0];
    }
    int space_optimization(int n,vector<int>& nums){
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);
        for(int curr = n-1;curr>=0;curr--){
            for(int prev = n-1;prev>=-1;prev--){
                int incl = 0;
                if(prev == -1 || nums[curr]>nums[prev]) incl = 1 + nextRow[curr+1];
                int excl = 0 + nextRow[prev+1];
                currRow[prev+1] = max(incl,excl);
            }
            // Shifting Logic...
            nextRow = currRow;
        }
        return currRow[0];
    }
    int expected_complexities(int n,vector<int>& nums){
        if(n == 0) return 0;
        vector<int> ans;
        ans.push_back(nums[0]); // First element is always added to the array
        for(int i=1;i<n;i++){
            if(nums[i]>ans.back()) ans.push_back(nums[i]);
            else{ // Calculate the just bigger element than nums[i] in the ans array
                int index = *lower_bound(ans.begin(),ans.end(),nums[i]);
                ans[index] = nums[i];
            }
        }
        return ans.size(); // The ans array will not be the increasing subsequence but its length is our ans.
    }
    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();

        // return solveRec(n,nums,0,-1);

        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solveMem(n,nums,0,-1,dp);

        // return solveTab(n,nums);

        return space_optimization(n,nums);
    }
};
