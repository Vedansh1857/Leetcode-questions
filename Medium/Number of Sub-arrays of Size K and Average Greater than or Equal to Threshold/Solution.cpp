class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int i=0;
        int j=k;
        int sum = 0;
        for(int i=0;i<k;i++){
            sum += arr[i];
        }
        int ans = 0;
        if((sum/k) >= threshold) ans++;
        while(j<n){
            sum = sum+arr[j]-arr[j-k];
            if((sum/k) >= threshold) ans++;
            j++;
        }
        return ans;
    }
};
