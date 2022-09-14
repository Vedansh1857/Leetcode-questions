class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> :: iterator iter = nums.begin();
        while(iter != nums.end() && (iter+1) != nums.end()){
            int j = *(iter+1);
            if(*iter == j){
                return true;
                exit(0);
            }
            iter++;
        }
        return false;
    }
};
