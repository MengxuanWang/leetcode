/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.


Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

class Solution {
public:
    void dfs(vector<vector<string>>&res, vector<int>tmp, int n, int k) {
        if (n == k) {  // find a solution 
            vector<string> s(n, string(n, '.'));
            for (int i=0; i<n; i++) {
                int pos = tmp[i]; 
                s[i][pos] = 'Q';
            }
            res.push_back(s);
            return;
        }
        
        for (int i=0; i<n; i++) {
            int j = 0; 
            while (j < k) {
                if (tmp[j] == i || abs(tmp[j] - i) == (k - j)) break;
                j++;
            }
            if (j == k) {
                tmp.push_back(i); 
                dfs(res, tmp, n, k+1); 
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res; 
        vector<int> tmp; 
        dfs(res, tmp, n, 0); 
        return res;
    }
};