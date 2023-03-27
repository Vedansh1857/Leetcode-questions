class Solution {
public:
    int solveRec(string& text1, string& text2, int i,int j){
        // BASE CASE...
        if(i == text1.size() || j == text2.size()) return 0;
        if(text1[i] == text2[j]) return solveRec(text1,text2,i+1,j+1)+1;
        int textOne = solveRec(text1,text2,i+1,j);
        int textTwo = solveRec(text1,text2,i,j+1);
        return max(textOne,textTwo);
    }
    int solveMem(string& text1, string& text2, int i,int j, vector<vector<int>>& dp){
        // BASE CASE...
        if(i == text1.size() || j == text2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j]) return solveMem(text1,text2,i+1,j+1,dp)+1;
        int textOne = solveMem(text1,text2,i+1,j,dp);
        int textTwo = solveMem(text1,text2,i,j+1,dp);
        dp[i][j] = max(textOne,textTwo);
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // return solveRec(text1,text2,0,0);

        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1, vector<int> (n2+1,-1));
        return solveMem(text1,text2,0,0,dp);
    }
};



