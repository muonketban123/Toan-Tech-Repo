// 49. Group Anagrams
// Medium
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:

// Input: strs = [""]
// Output: [[""]]
// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]
 

// Constraints:

// 1 <= strs.length <= 10^4
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> hash_map;
        int index = 0;
        for(auto str : strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            if(hash_map.find(sorted_str) == hash_map.end()) {
                hash_map[sorted_str] = index;
                res.push_back({str});
                index++;
            }
            else {
                res[hash_map[sorted_str]].push_back(str);
            }
        }
        return res;
    }
};

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution s;
    vector<vector<string>> res = s.groupAnagrams(strs);
    for(auto t : res) {
        for(auto k : t) {
            cout << k << " ";
        }
        cout << endl;
    }
}