class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        set<char> Set;
        int start = 0;
        int end = 0;
        while(start<s.size()){
            auto it = Set.find(s[start]);
            if(it == Set.end()){
                maxi = max(maxi,start-end+1);
                Set.insert(s[start]);
                start++;
            }
            else{
                Set.erase(s[end]);
                end++;
            }
        }
        return maxi;
    }
};
