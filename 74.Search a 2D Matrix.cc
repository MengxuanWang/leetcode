/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m-1; 
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (matrix[mid][0] == target) return true; 
            if (matrix[mid][0] < target) left = mid + 1; 
            else right = mid - 1;
        }
        int row = right;
        if (row < 0) return false;
        left = 0; right = n-1; 
        while (left <= right) {
            mid = (left + right) / 2; 
            if (matrix[row][mid] == target) return true; 
            if (matrix[row][mid] < target) left = mid + 1; 
            else right = mid - 1;
        }
        return false;
    }
};