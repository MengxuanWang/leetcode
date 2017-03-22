/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1"; 
        string prev = "1"; 
        string cur = "";
        for (int i=2; i<=n; i++) {
            cur = ""; 
            char prevChar = prev[0]; 
            int cnt = 1; 
            for (int j=1; j<prev.size(); j++) {
                if (prev[j] == prevChar) cnt ++;
                else {
                    cur += (to_string(cnt) + prevChar); 
                    prevChar = prev[j]; 
                    cnt = 1;
                }
            }
            cur += (to_string(cnt) + prevChar);
            prev = cur;
        }
        return cur;
    }
};