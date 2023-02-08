class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = INT_MIN;
        int first_half = values[0]+0;
        for(int j=1;j<n;j++){ // Loop from 1 till n cuz we have to look for a pair.
            ans = max(ans,(first_half+values[j]-j)); // Calculating the ans.
            first_half= max(first_half,values[j]+j); // Maximizing a[i]+i in order to maximize the final ans.
        }
        return ans;
    }
};
