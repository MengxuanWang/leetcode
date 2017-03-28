/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int size = words.size();
        if (size <= 1) return 0;
        vector<int> processedWords(size, 0); 
        for (int i=0; i<size; i++) {
            string word = words[i]; 
            for (int j=0; j<word.size(); j++) {
                processedWords[i] |= (1 << (word[j] - 'a'));
            }
        }
        int product = 0;
        for (int i=0; i<size-1; i++) {
            for (int j=i+1; j<size; j++) {
                if ((processedWords[i] & processedWords[j]) == 0) {
                    int tmp = words[i].size() * words[j].size(); 
                    if (tmp > product)  product = tmp;
                } 
            }
        }
        return product;
    }
};