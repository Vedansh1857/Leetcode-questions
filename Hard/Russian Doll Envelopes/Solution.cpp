class Solution {
public:
    static bool cmp(const vector<int>& v1, const vector<int>& v2)
    {
      if(v1[0] == v2[0]) return v1[1] > v2[1];
            return v1[0]<v2[0];
    }
    // Start sorting on the basis of width and if 2 widths are found to be equal then sort on the basis of height in reverse (i.e. descending order) and then apply the logic of LIS on the heights array...
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),cmp); 
        vector<int>arr;
        for(int i =0;i<n;i++)
        {
            if(arr.empty() || arr.back()<envelopes[i][1])
                arr.push_back(envelopes[i][1]);
            else
            {
                int index = lower_bound(arr.begin(),arr.end(),envelopes[i][1])
                        -   arr.begin();
                arr[index] = envelopes[i][1];
            }
        }
        
        return arr.size();
    }
};
