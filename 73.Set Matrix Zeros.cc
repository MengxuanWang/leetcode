/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); 
        int n = matrix[0].size(); 
        if (m == 0 || n == 0) return; 
        
        bool rowzero = false, colzero = false; 
        for (int i=0; i<m; i++) {
            if (matrix[i][0] == 0) {
                colzero = true; 
                break;
            }
        }
        for (int j=0; j<n; j++) {
            if (matrix[0][j] == 0) {
                rowzero = true;
                break;
            }
        }
        
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i=1; i<m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j<n; j++) matrix[i][j] = 0;
            }
        }
        for (int j=1; j<n; j++) {
            if (matrix[0][j] == 0) {
                for (int i=1; i<m; i++) matrix[i][j] = 0; 
            }
        }
        if (rowzero) {
            for (int j = 0; j<n; j++) matrix[0][j] = 0;
        }
        if (colzero) {
            for (int i=0; i<m; i++) matrix[i][0] = 0;
        }
    }
};