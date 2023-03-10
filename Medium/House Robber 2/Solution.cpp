// The solution to this is taken from problem "Max Sum without Adjacents" which is solved by me only step-by-step... So first refer to that before coming onto this one.

class Solution {
public:
    int solve(vector<int>& nums,int n){
        int prev2 = 0;
	    int prev1 = nums[0];
	    for(int i=1;i<n;i++){
	        int incl = prev2 + nums[i];
	        int excl = prev1 + 0;
	        int ans = max(incl,excl);
	        prev2 = prev1;
	        prev1 = ans;
	    }
	    return prev1;
    }
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> first; // This contains first element.
        vector<int> last; // This contains last element.
        for(int i=0;i<=n-2;i++) first.push_back(nums[i]);
        for(int i=1;i<=n-1;i++) last.push_back(nums[i]);
        return max(solve(first,n-1) , solve(last,n-1));
    }
};
