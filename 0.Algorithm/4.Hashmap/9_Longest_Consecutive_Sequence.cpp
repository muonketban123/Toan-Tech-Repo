// 128. Longest Consecutive Sequence
// Medium

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

 

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
 

// Constraints:

// 0 <= nums.length <= 10^5
// -10^9 <= nums[i] <= 10^9

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end()); // insert num : nums to set
        int res = 0;
        for(auto num : nums) {
            if(numSet.find(num -1) == numSet.end()) {
                int count = 1;
                int cur = num;
                while(numSet.find(cur + 1) != numSet.end()) {
                    count++;
                    cur++;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution s;
    cout << s.longestConsecutive(nums) << endl;
}