class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int i=0;
        vector<vector<int>> ans;
        vector<int> temp = intervals[0];
        for(auto it: intervals){
            if(it[0] <= temp[1]) temp[1]=max(temp[1],it[1]);
            else{
                ans.push_back(temp);
                temp=it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
