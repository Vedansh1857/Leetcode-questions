class Solution {
public:
    int lcs(string& text1, string& text2){
        vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size()+1,0));
        for(int i=text1.size()-1;i>=0;i--){
            for(int j=text2.size()-1;j>=0;j--){
                int ans = 0;
                if(text1[i] == text2[j]) ans = dp[i+1][j+1]+1;
                else{
                    int textOne = dp[i+1][j];
                    int textTwo = dp[i][j+1];
                    ans = max(textOne,textTwo);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        return lcs(s,rev);
    }
};


// The length of the longest palindromic subsequence of a string is -> only the length of LCS(Longest common subsequence) of the given string and reverse of the given string.
