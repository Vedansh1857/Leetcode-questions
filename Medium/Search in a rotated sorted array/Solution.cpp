class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;
        while(s<=e){
            if(nums[s] != target)
                s++;
            else
                return s;
        }
        return -1;
    }
};
