/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(); 
        int len2 = word2.size(); 
        int dp[len1+1][len2+1];
        for (int i=0; i<=len1; i++) dp[i][0] = i; 
        for (int j=0; j<=len2; j++) dp[0][j] = j;
        for (int i=0; i<len1; i++) {
            for (int j=0; j<len2; j++) {
                if (word1[i] == word2[j]) {
                    dp[i+1][j+1] = dp[i][j];
                } else {
                    int m = min(dp[i][j], dp[i][j+1]);
                    dp[i+1][j+1] = min(m, dp[i+1][j]) + 1;
                }
            }
        }
        return dp[len1][len2];
    }
};