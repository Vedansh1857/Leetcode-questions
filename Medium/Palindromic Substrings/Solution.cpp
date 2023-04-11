class Solution {
public:
    int solveRec(string& s,int i,int j){
        // BASE CASE...
        if(i>=j) return 1;
        if(s[i] == s[j]) return solveRec(s,i+1,j-1);
        return 0;
    }
    int countSubstrings(string s){
        int count = 0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                count += solveRec(s,i,j);
            }
        }
        return count;
    }
};
