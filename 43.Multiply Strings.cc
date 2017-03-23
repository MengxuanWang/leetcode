/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end()); 
        int size1 = num1.size(), size2 = num2.size(); 
        vector<int> tmp(size1+size2, 0); 
        for (int i=0; i<size1; i++) {
            for (int j=0; j<size2; j++) {
                tmp[i+j] += (num1[i]-'0') * (num2[j]-'0');
            }
        }
        string res="";
        for (int t=0; t<tmp.size(); t++) {
            int digit = tmp[t] % 10; 
            int carry = tmp[t] / 10; 
            if (t < tmp.size()-1) tmp[t+1] += carry;
            res = to_string(digit) + res;
        }
        int i=0;
        while (res[i] == '0' && i<res.size()-1) i++; 
        return res.substr(i);
    }
};