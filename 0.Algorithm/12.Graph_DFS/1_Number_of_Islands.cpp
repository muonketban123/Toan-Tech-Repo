// 200. Number of Islands
// Medium

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.


#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
private:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j) {
        int R = grid.size();
        int C = grid[0].size();
        vis[i][j] = 1;
        stack<pair<int,int>> st;
        st.push({i, j});

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while(!st.empty()) {
            int x = st.top().first;
            int y = st.top().second;
            st.pop();
            for(int i = 0; i < 4; ++i) {
                int rx = x + dr[i];
                int cy = y + dc[i];
                if(rx >= 0 && rx < R && cy >= 0 && cy < C && grid[rx][cy] == '1' && !vis[rx][cy]) {
                    vis[rx][cy] = 1;
                    st.push({rx,cy});
                }
            }
        }
    } 
public:
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        int res = 0;
        vector<vector<int>> vis(R, vector<int> (C,0));
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    res++;
                    dfs(grid, vis, i, j);
                }
            } 
        }
        return res;
    }
};

int main() {
    std::vector<std::vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    Solution sol;
    int islands = sol.numIslands(grid);
    std::cout << "Number of islands: " << islands << std::endl;

    return 0;
}