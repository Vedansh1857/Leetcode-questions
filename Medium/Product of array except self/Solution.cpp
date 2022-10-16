class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int prod1 = 1;
        int n = a.size();
        vector<int> prefix;
        prefix.push_back(1);
        for(int i=0;i<n;i++){
            prod1 *= a[i];
            prefix.push_back(prod1);
        }
        int prod2 = 1;
        vector<int> postfix;
        for(int i=n-1;i>=0;i--){
            prod2 *= a[i];
            postfix.push_back(prod2);
        }
        reverse(postfix.begin(),postfix.end());
        postfix.push_back(1);
        vector<int> ans;
        for(int i=1;i<=n;i++){
            int x = (prefix[i-1] * postfix[i]);
            ans.push_back(x);
        }
        return ans;
    }
};
