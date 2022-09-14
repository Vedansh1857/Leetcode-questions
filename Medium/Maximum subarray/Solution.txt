class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN, tmp = 0;
        for(int i = 0; i < nums.size(); i++){
            tmp += nums[i], mx = max(mx, tmp);
            if(tmp < 0)
                tmp = 0;}
        return mx;
    }
};
