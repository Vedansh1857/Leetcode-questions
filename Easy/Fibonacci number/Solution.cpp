class Solution {
public:
    int fib(int n) {
        int prev2 = 0;
        int prev1 = 1;

        if(n==0) return 0;

        for(int i=2;i<=n;i++){
            int curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
