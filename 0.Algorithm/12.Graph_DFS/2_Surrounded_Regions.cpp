// 130. Surrounded Regions
// Medium

// Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

// Example 1:


// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
// Explanation: Notice that an 'O' should not be flipped if:
// - It is on the border, or
// - It is adjacent to an 'O' that should not be flipped.
// The bottom 'O' is on the border, so it is not flipped.
// The other three 'O' form a surrounded region, so they are flipped.
// Example 2:

// Input: board = [["X"]]
// Output: [["X"]]
 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is 'X' or 'O'

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>> &board, int i, int j) {
        int R = board.size();
        int C = board[0].size();
        board[i][j] = '#';
        stack<pair<int, int>> st;
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
                if(rx >= 0 && rx < R && cy >= 0 && cy < C && board[rx][cy] == 'O') {
                    board[rx][cy] = '#';
                    st.push({rx, cy});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int R = board.size();
        int C = board[0].size();
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                if(i == 0 || j == 0 || i == R -1 || j == C -1) 
                {
                    if(board[i][j] == 'O') {
                        dfs(board, i, j);
                    }
                }
            }
        }
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};

int main() {
    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    Solution s;
    s.solve(board);
    for(auto t : board) {
        for(auto t1 : t) {
            cout << t1 << " ,";
        }
        cout << endl;
    }
}