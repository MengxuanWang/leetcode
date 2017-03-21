/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        vector<vector<int>> dp; 
        dp.push_back(triangle[0]); 
        int size = triangle.size();
        for (int i=1; i<size; i++) {
            vector<int> tmp; 
            for (int j=0; j<triangle[i].size(); j++) {
                if (j > 0 && j < triangle[i].size()-1) {
                    tmp.push_back(min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]);
                }
                else if (j == 0) {
                    tmp.push_back(dp[i-1][j] + triangle[i][j]);
                }
                else {
                    tmp.push_back(dp[i-1][j-1] + triangle[i][j]);
                }
            }
            dp.push_back(tmp);
        }
        int m = INT_MAX;
        for (int i=0; i<dp[size-1].size(); i++) {
            m = min(m, dp[size-1][i]);
        }
        return m;
    }
};