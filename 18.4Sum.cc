/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res; 
        int size = nums.size(); 
        sort(nums.begin(), nums.end());
        for (int i=0; i<size-3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue; 
            for (int j=i+1; j<size-2; j++) {
                if (j>i+1 && nums[j] == nums[j-1]) continue;
                int left = j+1, right = size-1; 
                int tmp = target - nums[i] - nums[j];
                while (left < right) {
                    if (nums[left] + nums[right] == tmp) {
                        vector<int> v; 
                        v.push_back(nums[i]); 
                        v.push_back(nums[j]); 
                        v.push_back(nums[left]); 
                        v.push_back(nums[right]);
                        res.push_back(v);
                        left ++; 
                        right --; 
                        while (left < right && nums[left] == nums[left-1]) left ++; 
                        while (left < right && nums[right] == nums[right+1]) right --;
                        continue;
                    }
                    if (nums[left] + nums[right] < tmp) left++; 
                    else right--;
                }
            }
        }
        return res;
    }
};