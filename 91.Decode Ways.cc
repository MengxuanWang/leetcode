/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

*/

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') return 0; 
        vector<int> dp;
        dp.push_back(1);
        dp.push_back(1);
        for (int i=2; i<=s.size(); i++) {
            int tmp = (s[i-2] - '0') * 10 + (s[i-1] - '0');   
            if ((tmp >= 10 && tmp <= 26) && (s[i-1] != '0')) {
                dp.push_back(dp[i-1] + dp[i-2]);
            } 
            else if (tmp == 10 || tmp == 20) {
                dp.push_back(dp[i-2]);
            }
            else if (s[i-1] != '0') {
                dp.push_back(dp[i-1]);
            }
            else {
                dp.push_back(0);
            }
        }
        return dp[s.size()];
    }
};