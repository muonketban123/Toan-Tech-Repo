#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; // If the vector is empty, return an empty string

        string ans = ""; // Initialize the result string
        int n = strs.size(); // Get the number of strings in the vector

        // Iterate over the characters of the first string
        for (int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i]; // Get the character at index i of the first string
            // Check if character c is common to all strings
            for (int j = 1; j < n; ++j) {
                // If index i is out of bounds for the current string or the character is not the same, return the result
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return ans;
                }
            }
            // If character c is common to all strings, append it to the result
            ans += c;
        }
        return ans; // Return the result
    }
};

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    Solution s;
    cout << s.longestCommonPrefix(strs);
    return 0;
}
