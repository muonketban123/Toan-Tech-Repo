// 407. Trapping Rain Water II
// Hard

// Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

 

// Example 1:


// Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
// Output: 4
// Explanation: After the rain, water is trapped between the blocks.
// We have two small ponds 1 and 3 units trapped.
// The total volume of water trapped is 4.
// Example 2:


// Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
// Output: 10
 

// Constraints:

// m == heightMap.length
// n == heightMap[i].length
// 1 <= m, n <= 200
// 0 <= heightMap[i][j] <= 2 * 10^4

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>> & heightMap) {
        if(heightMap.empty() || heightMap[0].empty()) {
            return 0;
        }

        int R = heightMap.size();
        int C = heightMap[0].size();
        vector<vector<int>> vis(R, vector<int> (C, 0));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int vol = 0;
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(i == 0 || i == R-1 || j == 0 || j == C -1) {
                    pq.push({heightMap[i][j], {i,j}});
                    vis[i][j] = true;
                }
            }
        }

        int minBht = 0;
        int dr[4] = {0, 0, -1, 1};
        int dc[4] = {-1, 1, 0, 0};
        while(!pq.empty()) {
            int curBht = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            minBht = max(curBht, minBht);
            for(int i = 0; i < 4; i++) {
                int rr = r + dr[i];
                int cc = c + dc[i];

                if(rr >= 0 && rr < R && cc >= 0 && cc < C && !vis[rr][cc]) {
                    pq.push({heightMap[rr][cc], {rr,cc}});
                    vis[rr][cc] = true;
                    if(heightMap[rr][cc] < minBht) {
                        vol += minBht - heightMap[rr][cc];
                    }
                }
            }
        }
        return vol;
    }
};
int main() {
    vector<vector<int>> hightMap  = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    Solution s;
    cout << s.trapRainWater(hightMap);
}


