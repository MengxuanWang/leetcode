/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true; 
        int left = 1, right = num / 2; 
        while (left <= right) {
            long mid = left + (right - left) / 2; 
            if (mid * mid == num) return true; 
            else if (mid * mid > num) right = mid - 1; 
            else left = mid + 1;
        }
        return false;
    }
};