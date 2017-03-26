/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int size = nums.size(); 
        if (size == 0) return res;
        int left = 0, right = size-1; 
        while (left < right-1) {
            int mid = (left + right) / 2; 
            if (nums[mid] == target)  {
                right = mid;  // 继续向左查找边界
            } 
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        if (nums[left] == target) res[0] = left; 
        else if (nums[right] == target) res[0] = right;
        else return res; 
        
        left = 0, right = size - 1; 
        while (left < right - 1) {
            int mid = (left + right) / 2; 
            if (nums[mid] == target) {
                left = mid; // 继续向右查找边界
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        if (nums[right] == target) res[1] = right; 
        else if (nums[left] == target) res[1] = left; 
        else return res;
        return res;
    }
};