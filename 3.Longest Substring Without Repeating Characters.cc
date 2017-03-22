/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/ 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m; 
        int maxLen = 0; 
        int curLen = 0; 
        for (int i=0; i<s.size(); i++) {
            if (m.find(s[i]) == m.end()) {
                curLen ++; 
                m.insert(make_pair(s[i], i));
            }
            else {
                int preidx = m[s[i]];
                curLen = min(curLen + 1, i - preidx); 
                m[s[i]] = i;
            }
            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};