// 58. Length of Last Word
// Easy
// Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal 
// substring
//  consisting of non-space characters only.

 

// Example 1:

// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.
// Example 2:

// Input: s = "   fly me   to   the moon  "
// Output: 4
// Explanation: The last word is "moon" with length 4.
// Example 3:

// Input: s = "luffy is still joyboy"
// Output: 6
// Explanation: The last word is "joyboy" with length 6.
 

// Constraints:

// 1 <= s.length <= 10^4
// s consists of only English letters and spaces ' '.
// There will be at least one word in s.
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int j = 0;
        for(int i = n -1; i >= 0; i--) {
            if(s[i] == ' ' && j == 0) 
                continue;
            if(s[i] != ' ') {
                j++;
            }
            else break;
        } 
        return j;
    }
};

// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         int n = s.length();
//         int count = 0;
//         int j = n-1, num = 0;
//         while(s[j] == ' ') {
//             num++;
//             j--;
//         }
//         for(int i = n - num - 1; i >= 0; i--) {
//             if(s[i] ==  ' ') {
//                 break;
//             }
//             else {
//                 count ++;
//             }
//         }
//         return count;
//     }
// };

int main() {
    Solution s;
    string st = "vu duc toan   ";
    cout << s.lengthOfLastWord(st);
}