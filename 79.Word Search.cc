/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/


class Solution {
public:
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>&visited, string& word, int idx, int i, int j) {
        idx ++;
        if (idx == word.size()) return true;
        
        visited[i][j] = true; 
        int x[4] = {-1, 0, 1, 0}; 
        int y[4] = {0, -1, 0, 1}; 
        int m = board.size(); 
        int n = board[0].size();
        for (int t = 0; t < 4; t++) {
            int new_i = i + x[t]; 
            int new_j = j + y[t];
            if ( new_i < 0 || new_i >= m) continue; 
            if ( new_j < 0 || new_j >= n) continue; 
            if (board[new_i][new_j] == word[idx] && !visited[new_i][new_j]) {
                if (dfs(board, visited, word, idx, new_i, new_j)) return true;
            } 
        }
        visited[i][j] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(); 
        int n = board[0].size(); 
        vector<vector<bool>> visited(m, vector<bool>(n, false)); 
        
        for (int i=0; i<m; i++) {
            for (int j =0; j<n; j++) {
                if (board[i][j] == word[0]) 
                    if (dfs(board, visited, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};