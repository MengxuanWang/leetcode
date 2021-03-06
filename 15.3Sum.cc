/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res; 
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i=0; i<size-2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1; 
            int right = size-1; 
            while (left < right) {
                if (nums[left] + nums[right] + nums[i] == 0) {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    res.push_back(tmp);
                    left ++;
                    right --;
                    while (left < right && nums[left] == nums[left-1]) left ++; 
                    while (left < right && nums[right] == nums[right+1]) right --;
                }
                else if (nums[left] + nums[right] + nums[i] < 0) left ++;
                else right --;
            }
        }
        return res;
    }
};