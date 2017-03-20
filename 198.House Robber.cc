/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        vector<int> res; 
        if (size == 1) return nums[0];
        if (size == 2) return max(nums[0], nums[1]);
        res.push_back(nums[0]);
        res.push_back(max(nums[0], nums[1])); 
        for (int i=2; i<size; i++) {
            res.push_back(max(res[i-1], res[i-2] + nums[i]));
        }
        return res[size-1];
    }
};