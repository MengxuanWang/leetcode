/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        pair<string, int> cur;
        int n = beginWord.size();
        set<string> words(wordList.begin(), wordList.end());
        while (!q.empty() && !words.empty()) {
            cur = q.front();
            q.pop(); 
            string word = cur.first;
            int length = cur.second;
            char oldChar = ' ';
            for (int i=0; i<n; i++) {
                oldChar = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (word[i] == c) continue; 
                    word[i] = c; 
                    if (words.find(word) != words.end()) {
                        if (word == endWord) return length + 1;
                        q.push(make_pair(word, length+1));
                        words.erase(word);
                    }
                    word[i] = oldChar;  
                }
            }
        }
        return 0;
    }
}