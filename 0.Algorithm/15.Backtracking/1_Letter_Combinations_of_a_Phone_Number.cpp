#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Solution {
private:
    void backTrack(string combination, vector<string> phone_map, string next_digits, vector<string> & output) {
        if(next_digits.empty()) {
            output.push_back(combination);
            return;
        }

        string letters = phone_map[next_digits[0] -'2'];
        for(auto letter : letters) {
            backTrack(combination + letter, phone_map, next_digits.substr(1), output);
        }
    }
public: 
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> res;
        vector<string> phone_map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backTrack("", phone_map, digits, res);
        return res;
    }
};


int main() {
    string digits = "23";
    Solution s;
    vector<string> res = s.letterCombinations(digits);
    for(auto t : res) {
        cout << t << " ";
    }
}