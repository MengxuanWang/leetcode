/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

class Solution {
public:
    void getNext(const string &substr, vector<int> &next) {
        next.clear();
        next.resize(substr.size());
        int j = -1;
        next[0] = -1;
        for (int i=1; i<substr.size(); i++) {
            while (j > -1 && substr[j+1] != substr[i])
                j = next[j];
            if (substr[j+1] == substr[i]) 
                ++j;
            next[i] = j;
        }
    }
    
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        vector<int> next;
        getNext(needle, next);
        
        int j = -1;
        for (int i=0; i<haystack.size(); i++) {
            while (j > -1 && needle[j+1] != haystack[i]) 
                j = next[j];
            if (needle[j+1] == haystack[i]) 
                ++j;
            if (j == needle.size() -1) {
                return i-j;
            }
        }
        return -1;
    }
};