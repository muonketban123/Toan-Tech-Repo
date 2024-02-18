// 290. Word Pattern
// Easy

// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

// Example 1:

// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
// Example 2:

// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false
// Example 3:

// Input: pattern = "aaaa", s = "dog cat cat dog"
// Output: false

// Constraints:

// 1 <= pattern.length <= 300
// pattern contains only lower-case English letters.
// 1 <= s.length <= 3000
// s contains only lowercase English letters and spaces ' '.
// s does not contain any leading or trailing spaces.
// All the words in s are separated by a single space.

#include <iostream>
#include <set>
#include <unordered_map>
#include <string.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string p, string s) {
        int n = p.length();
        set<char> st1;
        set<string> st2;
        unordered_map<char, string> mp;
        string curr = "";
        s.push_back(' ');
        int j = 0;
        for(auto ch : p) st1.insert(ch);
        for(int i = 0; i < s.length(); ++i) {
            if(j == p.length()) return false;
            if(s[i] == ' ') {
                if(mp.find(p[j]) == mp.end()) {
                    mp[p[j]] = curr;
                }
                else if(mp[p[j]] != curr) 
                    return false;
                j++;
                st2.insert(curr);
                curr.clear(); // curr = "";
            }
            else {
                curr.push_back(s[i]);
            }
        }
        return st1.size() == st2.size();
    }
};

int main() {
    string pattern = "abba";
    string s = "dog cat cat dog";
    Solution so;
    if(so.wordPattern(pattern, s))
        cout << "ok " << endl;
    else 
        cout << "not ok" << endl;
}