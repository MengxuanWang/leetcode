/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size(); 
        bool dp[size+1]; 
        memset(dp, false, sizeof(dp));
        dp[0] = true; 
        set<string> words(wordDict.begin(), wordDict.end());
        set<string>::iterator iter = words.begin(); 
        int maxLength = 0;
        for (iter; iter != words.end(); iter++) {
            if ((*iter).size() > maxLength) maxLength = (*iter).size();
        }
        for (int i=1; i<=size; i++) {
            for (int j=1; j<=maxLength && j<=i; j++) {
                if (!dp[i-j]) continue; 
                string word = s.substr(i-j, j); 
                if (words.find(word) != words.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[size];
    }
};