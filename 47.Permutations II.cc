/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> res; 
        res.push_back(nums); 
        int size = nums.size();
        while (true) {
            int i=size-1;
            while (i > 0) {
                if (nums[i-1] < nums[i]) break;
                i--;
            }
            if (i == 0) {
                return res;
            }
            int j = size-1;
            while (j >= i) {
                if (nums[j] > nums[i-1]) {
                    swap(nums[j], nums[i-1]);
                    break;
                }
                j--;
            }
            for (int t=0; t<(size-i)/2; t++) {
                swap(nums[i+t], nums[size-1-t]);
            }
            res.push_back(nums);
        }
    }
};