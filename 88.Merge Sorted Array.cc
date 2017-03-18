/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

class Solution {
public:
    // solution 1
    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     int i = 0, j = 0; 
    //     for (; j < n; j++) {
    //         while (i < m+j && nums1[i] <= nums2[j]) {
    //             i ++;
    //         }
    //         for (int t = m+j; t > i; t--) {
    //             nums1[t] = nums1[t-1];
    //         }
    //         nums1[i] = nums2[j]; 
    //         i ++;
    //     }
    // }
    
    // solution 2
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m + n - 1, i = m - 1, j = n - 1; 
        while (i >= 0 && j >= 0) {
            nums1[pos--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--]; 
        }
        while (i >= 0) {
            nums1[pos--] = nums1[i--];
        }
        while (j >= 0) {
            nums1[pos--] = nums2[j--];
        }
    }
};