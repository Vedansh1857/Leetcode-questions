class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(),a.end());
        vector<vector<int>> vec;
        set<vector<int>> s;
        int n = a.size();
        for(int i=0;i<n-2;i++){
            int val = a[i];
            int l=i+1;
            int r = n-1;
            while(l<r){
                int sum = val+a[l]+a[r];
                if(sum == 0) s.insert({val,a[l++],a[r--]});
                else if(sum<0) {l++;}
                else {r--;}
            }
        }
        for(auto x : s){
            vec.push_back(x);
        }
        return vec;
    }
};
