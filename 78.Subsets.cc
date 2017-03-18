/*
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/


class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& tmp, vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            res.push_back(tmp);
            return;
        }
        
        helper(res, tmp, nums, idx+1); 
        tmp.push_back(nums[idx]); 
        helper(res, tmp, nums, idx+1); 
        tmp.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res; 
        vector<int> tmp; 
        helper(res, tmp, nums, 0); 
        return res;
    }
};