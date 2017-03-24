/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size(); 
        int start = 0, end = 0;
        int step = 0;
        while (end < size-1) {
            int tmp = 0; 
            step ++;
            for (int i=start; i<=end; i++) {
                tmp = max(tmp, nums[i] + i);
            }
            if (tmp >= size-1) return step; 
            start = end + 1; 
            end = tmp;
            if (start > end) break;
        } 
        return step;
    }
};
