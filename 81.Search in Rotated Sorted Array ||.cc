/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // 1,2,3,3,3,3,3    3,3,3,3,3,1,2    3,1,2,3,3,3,3
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target || nums[left] == target || nums[right] == target) {
                return true;
            }
            if (nums[left] < nums[mid]) {
                if (nums[left] < target && nums[mid] > target) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else if (nums[left] > nums[mid]) {
                if (nums[mid] < target && nums[right] > target) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            else {
                left ++;
            }
        }
        return false;
    }
};