// 42. Trapping Rain Water
// Hard

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

// Example 1:


// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9
 

// Constraints:

// n == height.length
// 1 <= n <= 2 * 10^4
// 0 <= height[i] <= 10^5

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l_max = height[0];
        int r_max = height[n-1];
        int l_pos = 1;
        int r_pos = n-2;
        int water = 0;
        while(l_pos <= r_pos) {
            if(l_max <= height[l_pos]) {
                l_max = height[l_pos];
                l_pos++;
            } 
            else if(r_max <= height[r_pos]) {
                r_max = height[r_pos];
                r_pos--;
            } else if(l_max <= r_max && height[l_pos] < l_max) {
                water += l_max - height[l_pos];
                l_pos++;
            } else {
                water += r_max - height[r_pos];
                r_pos--;
            }
        }
        return water;
    }
};


int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution s;
    cout << s.trap(height) << endl;
}