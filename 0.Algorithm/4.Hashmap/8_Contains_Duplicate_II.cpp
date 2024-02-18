// 219. Contains Duplicate II
// Easy

// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

// Example 1:

// Input: nums = [1,2,3,1], k = 3
// Output: true
// Example 2:

// Input: nums = [1,0,1,1], k = 1
// Output: true
// Example 3:

// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false
 

// Constraints:

// 1 <= nums.length <= 10^5
// -10^9 <= nums[i] <= 10^9
// 0 <= k <= 10^5

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsNearDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); ++i) {
            if(mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k)
                return true;
            mp[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    Solution s;
    if(s.containsNearDuplicate(nums, k)) {
        cout << "true " << endl;
    } else {
        cout << "false " << endl; 
    }
}