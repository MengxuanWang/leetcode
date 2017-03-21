/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size(); 
        int len3 = s3.size(); 
        if (len1 + len2 != len3) return false; 
        if (s1 == "") return s2 == s3; 
        if (s2 == "") return s1 == s3; 
        bool dp[len1+1][len2+1]; 
        memset(dp, false, sizeof(dp)); 
        for (int i=1; i<=len1; i++) {
            if (s1[i-1] != s3[i-1]) break; 
            dp[i][0] = true;
        } 
        for (int j=1; j<=len2; j++) {
            if (s2[j-1] != s3[j-1]) break; 
            dp[0][j] = true;
        }
        for (int i=1; i<=len1; i++) {
            for (int j=1; j<=len2; j++) {
                if (dp[i-1][j] && s1[i-1] == s3[i+j-1]) {
                    dp[i][j] = true;
                    continue;
                }
                if (dp[i][j-1] && s2[j-1] == s3[i+j-1]) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[len1][len2];
    }
};