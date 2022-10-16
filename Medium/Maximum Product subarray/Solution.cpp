class Solution {
public:
    int maxProduct(vector<int>& a) {
        int maxp = INT_MIN;
        int n = a.size();
        int prod1 = 1;
        vector<int> prefix;
        for(int i=0;i<n;i++){
            prod1 *= a[i];
            maxp = max(maxp,prod1);
            if(prod1 == 0) prod1 = 1;
        }
        // int pre_max = *max_element(prefix.begin(),prefix.end());
        int prod2 = 1;
        vector<int> postfix;
        for(int i=n-1;i>=0;i--){
            prod2 *= a[i];
            maxp = max(maxp,prod2);
            if(prod2 == 0) prod2 = 1;
        }
        // int post_max = *max_element(postfix.begin(),postfix.end());
        // reverse(postfix.begin(),postfix.end());
        // int ans = max(pre_max , post_max);
        return maxp;
    }
};
