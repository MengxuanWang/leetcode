/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size == 0) return ""; 
        
        int left=0, right=0; 
        int l=0, r=0;
        for (int i=0; i<size*2-1; i++) {
            if (i % 2 == 0) {
                left = i/2; 
                right = i/2;
            } else {
                left = i/2;
                right = i/2 + 1;
            }
            while (left >=0 && right <size && s[left] == s[right]) {
                left --;
                right ++;
            }
            left ++;
            right --;
            if ((right - left) > (r - l)) {
                r = right; 
                l = left;
            }
        }
        return s.substr(l, (r-l+1));
    }
};