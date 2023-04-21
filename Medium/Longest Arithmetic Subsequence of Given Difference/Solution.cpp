class Solution {
public:
    // Applying the logic of LIS, which is also correct but 6 test cases are not passing giving TLE...
    int space_optimization(int n,vector<int>& nums,int diff){
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);
        for(int curr = n-1;curr>=0;curr--){
            for(int prev = n-1;prev>=-1;prev--){
                int incl = 0;
                if(prev == -1 || nums[curr]-nums[prev] == diff) incl = max(incl,1+nextRow[curr+1]);
                int excl = 0 + nextRow[prev+1];
                currRow[prev+1] = max(incl,excl);
            }
            // Shifting Logic...
            nextRow = currRow;
        }
        return currRow[0];
    }
    int dpPlusHashing(vector<int>& arr,int n,int diff){
        unordered_map<int,int> dp; // Bcz it supports faster seraching. key=starting element of the AP & values=length of AP.
        int ans = 0;
        for(int i : arr){
            int tmp = i-diff; // Calculating difference of each element and the diff
            int tempAns = 0;
            if(dp.count(tmp)) tempAns = dp[tmp]; // If the difference calculated above is already present in the map then just update the temporary answer...
            dp[i] = 1+tempAns; // And then update the hashmap...
        }
        for (auto& it : dp) if (it.second > ans) ans = it.second; // The max element gives the required length...
        return ans;
    }
    int longestSubsequence(vector<int>& arr, int difference){
        int n = arr.size();
        // return space_optimization(n,arr,difference);

        return dpPlusHashing(arr,n,difference);
    }
};
