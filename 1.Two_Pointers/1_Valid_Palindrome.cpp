// 125. Valid Palindrome
// Easy
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

 

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.
 

// Constraints:

// 1 <= s.length <= 2 * 10^5
// s consists only of printable ASCII characters

//Goi y:
//isalnum
//tolower

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;
        while(start <= end) {
            if(!isalnum(s[start])) {
                start++;
                continue;
            }
            if(!isalnum(s[end])) {
                start++;
                continue;
            }
            if(tolower(s[start]) != tolower(s[end])) return false;
            else {
                start++;
                end--;
            }
        }
        return true;
    }
};


int main() {
    Solution s;
    string str = "A man, a plan, a canal: Panama";
    bool check = s.isPalindrome(str);
    if(check) {
        cout << "ok" << endl;
    } else {
        cout << "not ok" << endl;
    }
}