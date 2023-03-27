class Solution {
public:
    int lcs(string& text1, string& text2, int i,int j, vector<vector<int>>& dp){
        // BASE CASE...
        if(i == text1.size() || j == text2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j]) return lcs(text1,text2,i+1,j+1,dp)+1;
        int textOne = lcs(text1,text2,i+1,j,dp);
        int textTwo = lcs(text1,text2,i,j+1,dp);
        dp[i][j] = max(textOne,textTwo);
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int> (n2+1,-1));
        return n1 + n2 - 2*(lcs(word1,word2,0,0,dp));
    }
};
