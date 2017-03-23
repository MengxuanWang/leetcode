/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

class Solution {
public:
    int count = 0; 
    void dfs(vector<int>tmp, int n, int k) {
        if (n == k) {
            count ++; 
            return;
        }
        
        for (int i=0; i<n; i++) {
            int j = 0;
            while (j < k) {
                if (i == tmp[j] || abs(tmp[j] - i) == (k - j)) break; 
                j++;
            }
            if (j == k) {
                tmp.push_back(i);
                dfs(tmp, n, k+1); 
                tmp.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        vector<int> tmp; 
        dfs(tmp, n, 0); 
        return count;
    }
};