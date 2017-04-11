/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // solution 1
        // map<int, int> m; 
        // for (int i=0; i<nums.size(); i++) {
        //     if (m.find(nums[i]) != m.end()) return true; 
        //     m.insert(pair<int, int>(nums[i], i));
        // }
        // return false;
        
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }
};