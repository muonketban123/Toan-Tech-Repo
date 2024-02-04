// 28. Find the Index of the First Occurrence in a String
// Easy
// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
// Example 2:

// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

// Constraints:

// 1 <= haystack.length, needle.length <= 10^4
// haystack and needle consist of only lowercase English characters.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        bool check = false;
        for(int i = 0; i < m; i++) {
            if(haystack[i] == needle[0]) {
                check = true;
                int cur = i + 1;
                for(int k = 1; k < n; k++) {
                    if(haystack[cur] == needle[k]) {
                        cur++;
                    }
                    else 
                    {
                        check = false;
                        break;
                    }   
                }
            }
            if(check) 
                return i;
        }
        return -1;
    }
};

int main() {
    string haystack = "vuductoan";
    string needle = "toan";
    Solution s;
    cout << s.strStr(haystack, needle);
}