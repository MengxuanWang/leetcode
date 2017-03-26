/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    // int findMin(vector<int>& nums) {
    //     int size = nums.size(); 
    //     if (size == 1) return nums[0]; 
    //     int left = 0, right = size - 1; 
    //     while (left < right) {
    //         if (nums[left] < nums[right]) return nums[left]; 
    //         int mid = (left + right) / 2; 
    //         if (nums[left] < nums[mid])  {
    //             left = mid;
    //         }
    //         else if (nums[left] > nums[mid]) {
    //             right = mid;
    //         }
    //         else {
    //             return min(nums[left], nums[right]);
    //         }
    //     }
    //     return 0;
    // }
    
    // solution 2 
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return nums[0]; 
        int left = 0, right = size - 1; 
        while (nums[left] > nums[right]) {
            int mid = (left + right) / 2; 
            if (nums[mid] > nums[right]) left = mid + 1; 
            else right = mid;
        }
        return nums[left];
    }
};