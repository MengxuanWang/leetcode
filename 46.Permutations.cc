/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/


class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& nums, int n) {
        if (n == 0) {
            res.push_back(nums);
            return; 
        }
        
        for (int i=0; i<=n; i++) {
            swap(nums[i], nums[n]); 
            helper(res, nums, n-1);
            swap(nums[i], nums[n]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res; 
        int size = nums.size();
        if (size == 0) {
            res.push_back(vector<int>());
        }
        helper(res, nums, size-1);
        return res;
    }
};