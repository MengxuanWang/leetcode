/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

// class Solution {
// public:
//     struct Parenthese {
//         char chr; 
//         int idx; 
//         Parenthese(int i, char c):idx(i),chr(c) {} 
//     };
//     int longestValidParentheses(string s) {
//         stack<Parenthese> stk; 
//         int count = 0;
//         for (int i=0; i<s.size(); i++) {
//             if (s[i] == '(') {
//                 stk.push(Parenthese(i, '('));
//             }else {
//                 if (!stk.empty() && stk.top().chr == '(') {
//                     stk.pop(); 
//                     int curlen = 0;
//                     if (stk.empty()) {
//                         curlen = i + 1;
//                     } else {
//                         curlen = i - stk.top().idx;
//                     }
//                     count = max(count, curlen);
//                 }else {
//                     stk.push(Parenthese(i, ')'));
//                 }
//             }
//         }
//         return count;
//     }
// };

// Solution 2 DP
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s == "") return 0; 
        int size = s.size(); 
        vector<int> dp(size, 0); 
        int count = 0;
        for (int i=size-2; i>=0; i--) {
            if (s[i] == '(') {
                int end = i + dp[i+1] + 1; 
                if (end < size && s[end] == ')') {
                    dp[i] = dp[i+1] + 2;
                    if (end + 1 < size) dp[i] += dp[end+1];
                    count = max(count, dp[i]);
                }
            }
        }
        return count;
    }
};