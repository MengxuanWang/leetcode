/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0; 
        int size = prices.size(); 
        int nums[size-1]; 
        for (int i=1; i<size; i++)
            nums[i-1] = prices[i] - prices[i-1];
        int sum = 0;
        int m = 0; 
        for (int i=0; i<size-1; i++) {
            if (sum < 0) sum = 0; 
            sum = sum + nums[i]; 
            m = max(sum, m);
        }
        return m;
    }
};