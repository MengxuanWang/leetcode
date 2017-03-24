/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size(); 
        int i = size - 1; 
        while (i > 0) {
            if (nums[i-1] < nums[i]) break;
            i--;
        }
        if (i == 0) {
            for (int j=0; j<size/2; j++) {
                swap(nums[i+j], nums[size-1-j]);
            }
            return;
        }
        int j = size-1;
        while (j >=i) {
            if (nums[j] > nums[i-1]) {
                swap(nums[i-1], nums[j]);
                break;
            }
            j--;
        }
        for (int t=0; t<(size-i)/2; t++) {
            swap(nums[i+t], nums[size-1-t]);
        }
    }
};