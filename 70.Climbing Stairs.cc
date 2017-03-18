/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n; 
        vector<int> dp; 
        dp.push_back(1); 
        dp.push_back(2); 
        for (int i=2; i<n; i++) {
            dp.push_back(dp[i-1] + dp[i-2]);
        }
        return dp[n-1];
    }
};