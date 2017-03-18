/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    void helper(int left, int right, string tmp, vector<string>& res) {
        if (right < left) return; 
        if (left == 0 && right == 0) res.push_back(tmp); 
        if (left > 0) {
            helper(left-1, right, tmp+'(', res);
        }
        if (right > 0) {
            helper(left, right-1, tmp+')', res);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 0) return res;
        helper(n, n, "", res);
        return res;
    }
};