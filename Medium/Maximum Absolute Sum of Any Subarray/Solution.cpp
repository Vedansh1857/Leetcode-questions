class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n;i++){
            nums[i] += nums[i-1];
        }
        int mi = *min_element(nums.begin(),nums.end()); 
        int mx = *max_element(nums.begin(),nums.end()); 
        if(mi >= 0) return mx;
        else if(mx < 0) return abs(mi);
        else return (abs(mi) + mx);
    }
};
