// 20. Valid Parentheses
// Easy

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false
 

// Constraints:

// 1 <= s.length <= 10^4
// s consists of parentheses only '()[]{}'.

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if(st.empty() == false) {
                    if(s[i] == ')' && st.top() == '(') st.pop();
                    else if(s[i] == ']' && st.top() == '[') st.pop();
                    else if(s[i] == '}' && st.top() == '{') st.pop();
                } else return false;
            }
        }
        if(st.empty() == true) return true;
        return false;
    }
};

int main() {
    string st = "(){}[]";
    Solution s;
    if(s.isValid(st)) 
        cout << "ok" << endl;
    else 
        cout << "not ok" << endl;
}