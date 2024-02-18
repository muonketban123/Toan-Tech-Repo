// 205. Isomorphic Strings
// Easy

// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

// Example 1:

// Input: s = "egg", t = "add"
// Output: true
// Example 2:

// Input: s = "foo", t = "bar"
// Output: false
// Example 3:

// Input: s = "paper", t = "title"
// Output: true
 

// Constraints:

// 1 <= s.length <= 5 * 10^4
// t.length == s.length
// s and t consist of any valid ascii character.

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> map_s(128, 0);
        vector<char> map_t(128, 0);
        int len = s.length();
        for(int i = 0; i < len; ++i) {
            if(map_s[s[i]] != map_t[t[i]]) return false;
            map_s[s[i]]++;
            map_t[t[i]]++;
        }
        return true;
    }
};

int main() {
    string s = "egg";
    string t = "add";
    Solution so;
    if(so.isIsomorphic(s, t)) 
        cout << "ok " << endl;
    else 
        cout << "not ok " << endl;
}