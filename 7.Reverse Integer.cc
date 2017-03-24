/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
*/

// class Solution {
// public:
//     int reverse(int x) {
//         int res = 0;
//         int sign = 1;
//         if (x < 0) {
//             sign = -1; 
//             x = -x;
//         }
//         while (x) {
//             if ((INT_MAX - x % 10) / 10 < res) return 0;
//             res = res * 10 + x % 10; 
//             x /= 10;
//         }
//         return res * sign;
//     }
// };

// solution 2
class Solution {
public: 
    int reverse(int x) {
        long res = 0; 
        while (x) {
            res = res * 10 + x % 10; 
            x /= 10;
        }
        if (res > INT_MAX || res < INT_MIN) return 0; 
        return res;
    }
};