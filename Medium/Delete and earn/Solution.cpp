class Solution {
public:
    int solveRec(vector<int>& arr,int i,int n){
        // Base case...
        if(n<=i) return 0;
        int curr_value = arr[i];
        int curr_sum = arr[i];
        int ptr = i+1;
        while(ptr<n && arr[ptr] == curr_value){
            curr_sum += arr[ptr];
            ptr++;
        }
        while(ptr<n && arr[ptr] == curr_value+1) ptr++;
        return max(solveRec(arr,i+1,n) , curr_sum+solveRec(arr,ptr,n));
    }
    int solveMem(vector<int>& arr,int i,int n,vector<int>& dp){
        // Base case...
        if(n<=i) return 0;
        if(dp[i] != -1) return dp[i];
        int curr_value = arr[i];
        int curr_sum = arr[i];
        int ptr = i+1;
        while(ptr<n && arr[ptr] == curr_value){
            curr_sum += arr[ptr];
            ptr++;
        }
        while(ptr<n && arr[ptr] == curr_value+1) ptr++;
        return dp[i] = max(solveMem(arr,i+1,n,dp) , curr_sum+solveMem(arr,ptr,n,dp));
    }
    int deleteAndEarn(vector<int>& nums){
        // // Recursive approach...
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // return solveRec(nums,0,n);

        // Adding Memoization...
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n+1,-1);
        return solveMem(nums,0,n,dp);
    }
};
