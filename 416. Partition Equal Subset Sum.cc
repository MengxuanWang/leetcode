/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/

//Solution1 : TLE
// class Solution {
// public:
//     bool bfs(vector<int>& nums, int cur, int idx, int target) {
//         if (cur == target) return true; 
//         if (idx == nums.size() || cur > target) return false;
//         return bfs(nums, cur, idx+1, target) || bfs(nums, cur+nums[idx], idx+1, target); 
//     }
    
//     bool canPartition(vector<int>& nums) {
//         int sum = 0; 
//         for (auto num: nums) sum += num; 
//         if (sum % 2) return false; 
//         sort(nums.begin(), nums.end());
//         int target = sum / 2; 
//         return bfs(nums, 0, 0, target);
//     }
// };

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0); 
        if (sum & 1) return false; 
        vector<int> dp(sum/2+1, 0);
        dp[0] = 1; 
        for (int i=0; i<nums.size(); i++) {
            for (int j=sum/2; j>=nums[i]; j--) {
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[sum/2];
    }
};