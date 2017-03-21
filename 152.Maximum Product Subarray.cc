/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        vector<int> maxs(size, 0); 
        vector<int> mins(size, 0);
        int res = INT_MIN;
        for (int i=0; i<nums.size(); i++) {
            if (i == 0) {
                maxs[i] = nums[i]; 
                mins[i] = nums[i]; 
                res = max(res, maxs[i]); 
                continue;
            }
            int tmp1 = maxs[i-1] * nums[i]; 
            int tmp2 = mins[i-1] * nums[i]; 
            maxs[i] = max(max(tmp1, tmp2), nums[i]); 
            mins[i] = min(min(tmp1, tmp2), nums[i]); 
            res = max(res, maxs[i]);
        }
        return res;
    }
};