// 121. Best Time to Buy and Sell Stock
// Easy

// 29797

// 1055

// Add to List

// Share
// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.
 

// Constraints:

// 1 <= prices.length <= 10^5
// 0 <= prices[i] <= 10^4

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int min_now = INT_MAX; // min prices at the moment
        int res_temp = 0; // profit tempirity
        int res = 0; // max Profit
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < min_now) 
                min_now = prices[i];
            
            res_temp = prices[i] - min_now;
            res = max(res_temp, res);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(prices);
}