/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/

class Solution {
public: 
    bool isPalindrome(string s) {
        int len = s.size();
        for (int i=0; i < len/2; i++) {
            if (s[i] != s[len-1-i]) return false;
        }
        return true;
    }
    
    void dfs(string s, vector<string> &cur, vector<vector<string>> &res) {
        if (s == "") {
            res.push_back(cur);
            return;
        }
        for (int i=1; i<=s.size(); i++) {
            if (isPalindrome(s.substr(0, i))) {
                cur.push_back(s.substr(0, i));
                dfs(s.substr(i), cur, res);
                cur.pop_back();
            }
        }
    } 
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res; 
        vector<string> cur; 
        dfs(s, cur, res);
        return res;
    }
};