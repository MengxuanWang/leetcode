/*
Implement pow(x, n).
*/

class Solution {
public:
    double helper(double x, int n) {
        if (n == 0) return 1; 
        double tmp = helper(x, n/2);
        if (n % 2) return tmp * tmp * x; 
        else return tmp * tmp;
    }
    
    double myPow(double x, int n) {
        int sign = 1;
        if (n < 0) sign = -1; 
        n = abs(n); 
        double res = helper(x, n); 
        return (sign == 1 ? res : 1.0 / res);
    }
};