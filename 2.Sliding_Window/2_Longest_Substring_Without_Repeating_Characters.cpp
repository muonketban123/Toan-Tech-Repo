// 3. Longest Substring Without Repeating Characters
// Solved

// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

// Constraints:

// 0 <= s.length <= 5 * 10^4
// s consists of English letters, digits, symbols and spaces.

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> chars;
        int left = 0, right = 0;
        int n = s.length();
        if(n == 0) return 0;
        int res = INT_MIN;
        while(right < n) {
            auto it = chars.find(s[right]);
            if(it != chars.end() && it->second >= left) {
                left = it->second+1;
            } else {
                res = max(res, right - left + 1);
            }
            chars[s[right]] = right;
            right++;
        }
        return res;
    }
};

int main() {
    string str = "pwwkew";
    Solution s;
    cout << s.lengthOfLongestSubstring(str);
}