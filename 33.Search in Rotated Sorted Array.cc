/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int helper(vector<int>& nums, int target, int left, int right) {
        if (left > right) return -1;
        int mid = (left + right) / 2; 
        if (nums[mid] == target) return mid; 
        if (nums[left] == target) return left; 
        if (nums[right] == target) return right;
        if (nums[left] < nums[right]) {  // situation 1
            if (nums[mid] < target) {
                return helper(nums, target, mid+1, right);
            }
            else {
                return helper(nums, target, left, mid-1);
            }
        }
        else if (nums[left] < nums[mid]) { // situation 2
            if (nums[mid] > target && nums[left] < target) {
                return helper(nums, target, left, mid-1);
            }
            else {
                return helper(nums, target, mid+1, right);
            }
        }
        else { // situation 3
            if (nums[mid] < target && nums[right] > target) {
                return helper(nums, target, mid+1, right);
            }
            else {
                return helper(nums, target, left, mid-1);
            }
        } 
    }
    int search(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size() -1);
    }
};