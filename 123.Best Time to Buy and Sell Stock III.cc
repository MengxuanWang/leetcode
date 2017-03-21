/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0; 
        int size = prices.size(); 
        
        int left[size]; 
        int right[size]; 
        left[0] = 0;
        int Min = prices[0]; 
        for (int i=1; i<size; i++) {
            left[i] = max(left[i-1], prices[i] - Min); 
            Min = min(Min, prices[i]);
        }
        int Max = prices[size-1]; 
        right[size-1] = 0;
        for (int i=size-2; i>=0; i--) {
            right[i] = max(right[i+1], Max - prices[i]); 
            Max = max(Max, prices[i]);
        }
        
        int res = 0; 
        for (int i=0; i<size; i++) {
            res = max(res, left[i] + right[i]);
        }
        return res;
    }
};