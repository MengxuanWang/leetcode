/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m; 
        for (int i=0; i<nums.size(); i++) {
            if (m.find(nums[i]) != m.end()) {
                int j = m[nums[i]]; 
                if (i - j <= k) return true;
                m[nums[i]] = i;
            } else {
                m.insert(pair<int, int>(nums[i], i));
            }
        }
        return false;
    }
};