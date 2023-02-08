class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int inc = nums[0];
        int exc = 0;
        for(int i=1;i<=n-1;i++){
           int ninc = exc+nums[i];
            int nexc = max(exc,inc);
            inc=ninc;
            exc=nexc;
        }
        int ans = max(inc,exc);
        return ans;
    }
};
