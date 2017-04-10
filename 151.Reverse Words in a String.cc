/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.
*/

class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end()); 
        int n = s.size();
        int relen = 0;
        for (int i=0; i<n; i++) {
            if (s[i] != ' ') {
                if (relen != 0) s[relen++] = ' ';
                int j = i; 
                while (j < n && s[j] != ' ') s[relen++] = s[j++]; 
                reverse(s.begin() + relen - (j-i), s.begin() + relen);
                i = j;
            }
        }
        s.resize(relen);
    }
};