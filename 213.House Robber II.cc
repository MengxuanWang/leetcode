/*
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size(); 
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        if (size == 2) return max(nums[0], nums[1]);
        vector<int> dp(size); 
        dp[0] = 0;
        dp[1] = nums[1];
        for (int i=2; i<size; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        int res = dp[size-1];
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i=2; i<size; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return max(res, dp[size-2]);
    }
}; 