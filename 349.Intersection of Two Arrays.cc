/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         set<int> result; 
//         map<int, bool> m; 
//         for (auto a: nums1) {
//             m[a] = true;
//         }
//         for (auto b: nums2) {
//             if (m.find(b) != m.end()) {
//                 result.insert(b);
//             }
//         }
//         return vector<int>(result.begin(), result.end());
//     }
// };

// class Solution {
// public: 
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         sort(nums1.begin(), nums1.end()); 
//         sort(nums2.begin(), nums2.end()); 
//         vector<int> res; 
//         int i=0, j=0; 
//         while (i < nums1.size() && j < nums2.size()) {
//             if (nums1[i] == nums2[j]) {
//                 if (res.empty() || *prev(res.end()) != nums1[i]) {
//                     res.push_back(nums1[i]);
//                 }
//                 i++; 
//                 j++;
//             }
//             else if (nums1[i] < nums2[j]) i++; 
//             else j++;
//         }
//         return res;
//     }
// };

class Solution {
public: 
    bool binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1; 
        int mid;
        while (left <= right) {
            mid = (left + right) / 2; 
            if (nums[mid] == target) return true; 
            else if (nums[mid] < target) left = mid + 1; 
            else right = mid - 1;
        }
        return false;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end()); 
        set<int> res; 
        for (auto a: nums2) {
            if (binarySearch(nums1, a)) res.insert(a);
        }
        return vector<int>(res.begin(), res.end());
    }
};