class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=1;
        auto it = nums.rbegin();
        while(n<k){
            it++;
            n++;
        }
        int ans = *(it);
        return ans;
    }
};
