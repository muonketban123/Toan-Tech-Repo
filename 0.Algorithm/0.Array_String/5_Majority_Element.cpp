// 169. Majority Element
// Easy

// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2
 

// Constraints:

// n == nums.length
// 1 <= n <= 5 * 10^4
// -10^9 <= nums[i] <= 10^9

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int res = 0;
//         map<int, int> maps;
//         for(auto t : nums) {
//             maps[t] ++;
//         }
//         for(auto j : maps) {
//             if(j.second > (nums.size()/2)) {
//                 res = j.first;
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
    }
};

int main() {
    vector<int> nums = {3, 2, 3};
    Solution s;
    cout << s.majorityElement(nums) << endl;
}