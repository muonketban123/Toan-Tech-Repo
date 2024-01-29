// 238. Product of Array Except Self
// Medium

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
 

// Constraints:

// 2 <= nums.length <= 10^5
// -30 <= nums[i] <= 30
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

// Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int check_ele_0 = 0;
        int j = 0;
        int product = 1;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                check_ele_0++;
                j = i;
            } else {
                product *= nums[i];
            }
        }
        if(check_ele_0 == 1) {
            for(int i = 0; i < nums.size(); i++) {
                nums[i] = 0;
            }
            nums[j] = product;
            return nums;
        }
        if(check_ele_0 > 1) {
            for(int i = 0; i < nums.size(); i++) {
                nums[i] = 0;
            }
            return nums;
        }

        for(int k = 0; k < nums.size(); k++) {
            nums[k] = product / nums[k];
        }
        return nums;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution s;
    vector<int> res = s.productExceptSelf(nums);
    for(auto t : res) {
        cout << t << " ";
    }
}