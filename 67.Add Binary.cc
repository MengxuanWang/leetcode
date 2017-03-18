/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res=""; 
        int carry = 0;
        int val = 0;
        int i=0, j=0;
        while (true) {
            if (i < a.size()) {
                carry += (a[i] - '0');
                i++;
            }
            if (j < b.size()) {
                carry += (b[j] - '0');
                j++;
            }
            val = carry % 2;
            carry /= 2;
            res.insert(res.begin(), val + '0');
            if (i == a.size() && j == b.size() && carry == 0) break;
        }
        return res;
    }
};