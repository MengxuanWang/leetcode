/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x<=1) return x; 
        
        int left = 1, right = x / 2; 
        long mid = (left + right) / 2; // 不能用int  mid*mid会溢出
        while (left <= right) {
            mid = (left + right) / 2;
            cout << mid << endl;
            if (mid * mid == x) return mid; 
            else if (mid * mid < x) 
                left = mid + 1;
            else 
                right = mid - 1; 
        }
        
        if (mid * mid < x) return mid;
        return mid - 1;
    }
};