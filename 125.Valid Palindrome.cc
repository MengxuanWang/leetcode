/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isalphanumber(char c) {
        return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
    
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        auto left = s.begin(), right = prev(s.end()); 
        while (left < right) {
            while (left < right && !isalphanumber(*left)) left ++; 
            while (left < right && !isalphanumber(*right)) right --;
            if (*left != *right) return false;
            left ++; 
            right --;
        }
        return true;
    }
};