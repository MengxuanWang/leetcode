/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/

// 注意判断是否溢出
class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int sign = 1; 
        int sum = 0; 
        while (i < str.size() && str[i] == ' ') i++; 
        if(i < str.size() && (str[i] == '-' || str[i] == '+')) {
            if (str[i] == '-') sign = -1; 
            i ++;
        }
        while (i < str.size() && (str[i] >= '0' && str[i] <= '9')) {
            int val = str[i] - '0';
            if ((INT_MAX - val) / 10 >= sum) {
                sum = sum * 10 + val; 
            } else {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            i++;
        }
        return sum * sign;
    }
};