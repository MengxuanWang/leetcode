/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
    void helper(vector<vector<int>>&res, vector<int>&tmp, int n, int k, int idx) {
        if (tmp.size() == k) {
            res.push_back(tmp); 
            return;
        }
        for (int i=idx; i<=n; i++) {
            tmp.push_back(i);
            helper(res, tmp, n, k, i+1);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res; 
        if (k <= 0) return res; 
        vector<int> tmp; 
        helper(res, tmp, n, k, 1);
        return res;
    }
};