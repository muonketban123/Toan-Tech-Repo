// 383. Ransom Note
// Easy

// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

 

// Example 1:

// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true
 

// Constraints:

// 1 <= ransomNote.length, magazine.length <= 10^5
// ransomNote and magazine consist of lowercase English letters.

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hash(256, 0);
        for(int i = 0; i < magazine.length(); ++i) {
            hash[magazine[i]]++;
        }
        for(int i = 0; i < ransomNote.length(); ++i) {
            hash[ransomNote[i]]--;
        }
        for(int i = 0; i < hash.size(); ++i) {
            if(hash[i] < 0) 
                return false;
        }
        return true;
    }
};

int main() {
    string ransomNote = "a";
    string magazine = "b";
    Solution s;
    if(s.canConstruct(ransomNote, magazine)) {
        cout << "ok " << endl;
    } else {
        cout << "not ok " << endl;
    }
}