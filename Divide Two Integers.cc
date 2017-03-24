/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1; 
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) sign = -1; 
        long a = (dividend > 0 ? dividend : -(long)dividend); 
        long b = (divisor > 0 ? divisor : -(long)divisor); 
        long res = 0; 
        int shift = 31; 
        while (shift >= 0) {
            if (a >= b << shift) {
                a -= b << shift;
                res += 1L << shift;
            }
            shift --;
        }
        res = ((dividend ^ divisor) >> 31) ? (-res): (res); 
        if (res > INT_MAX) return INT_MAX; 
        return res;
    }
};
