/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp; 
        dp.push_back(1); 
        dp.push_back(1);
        dp.push_back(2); 
        if (n <= 2) return dp[n]; 
        for (int i=3; i<=n; i++) {
            dp.push_back(0);
            for (int j=0; j<i; j++) {
                dp[i] += dp[j] * dp[i-1-j];
            } 
        }
        return dp[n];
    }
};