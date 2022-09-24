class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        int *left = new int[n];
        int *right = new int[n];
        left[0] = a[0];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],a[i]);
        }
        right[n-1] = a[n-1];
        for(int j=n-2;j>=0;j--){
            right[j] = max(right[j+1],a[j]);
        }
        int ans = 0;
        for(int k=0;k<n;k++){
            ans += (min(left[k] , right[k])) - a[k];
        }
        return ans;
    }
};
