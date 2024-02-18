// 242. Valid Anagram
// Easy

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
 

// Constraints:

// 1 <= s.length, t.length <= 5 * 10^4
// s and t consist of lowercase English letters.
 

// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

#include <iostream>
#include <unordered_map>
#include <string.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        for(auto ch : s) {
            mp[ch]++;
        }
        for(auto ch1 : t) {
            mp[ch1]--;
        }
        for(auto t : mp) {
            if(t.second != 0)
                return false;
        }
        return true;
    }
};

int main() {
    string s = "anagram";
    string t = "nagaram";
    Solution so;
    if(so.isAnagram(s, t))
        cout << "ok " << endl;
    else
        cout << "not ok " << endl;
}