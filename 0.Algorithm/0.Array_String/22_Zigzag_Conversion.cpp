// 6. Zigzag Conversion
// Medium

// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);
 

// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
// Example 3:

// Input: s = "A", numRows = 1
// Output: "A"
 

// Constraints:

// 1 <= s.length <= 1000
// s consists of English letters (lower-case and upper-case), ',' and '.'.
// 1 <= numRows <= 1000

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(numRows <= 1) return s;
        int dir = -1;
        int j = 0;
        string res = "";
        vector<string> t(numRows, "");
        for(int i = 0; i < n; i++) {
            if(j == 0 || j == numRows-1) dir *= -1;
            t[j] += s[i];
            j = j + dir;
        }
        for(auto k : t) {
            res += k;
        }
        return res;
    }
};

int main() {
    Solution s;
    string st = "PAYPALISHIRING";
    int numRows = 3;
    string res = s.convert(st, numRows);
    cout << res;
}