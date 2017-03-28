/*
Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int tmp = 0;
        int res = 0;
        for (int i=0; i<32; i++) {
            tmp = 0;
            for (int j =0; j<nums.size(); j++) {
                tmp += (nums[j] >> i & 1);
            } 
            res |= ((tmp % 3) << i);
        }
        return res;
    }
};